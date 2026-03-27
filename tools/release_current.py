#!/usr/bin/env python3

import argparse
import json
import os
import re
import sys
import zipfile
from hashlib import sha256
from pathlib import Path


DEFAULT_DEPENDENCIES = [
    {"packager": "tako0910", "name": "riscv-none-embed-gcc", "version": "8.2.0"},
    {"packager": "tako0910", "name": "openocd", "version": "1.0.0"},
    {"packager": "tako0910", "name": "beforeinstall", "version": "1.0.0"},
]

EXCLUDED_DIRS = {
    ".git",
    ".github",
    "__pycache__",
    ".pytest_cache",
    ".mypy_cache",
    ".idea",
    ".vscode",
    "dist",
}

EXCLUDED_FILES = {
    ".DS_Store",
}


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Create a release ZIP from the current working tree and emit a package index snippet."
    )
    parser.add_argument("version", help="Release version, for example 1.0.5")
    parser.add_argument(
        "--repo-root",
        default=Path(__file__).resolve().parents[1],
        type=Path,
        help="Repository root to package",
    )
    parser.add_argument(
        "--output-dir",
        default=Path(__file__).resolve().parents[1] / "dist",
        type=Path,
        help="Directory where the archive will be written",
    )
    parser.add_argument(
        "--package-name",
        default="arduino_core_ch32",
        help="Base file name used for the archive",
    )
    parser.add_argument(
        "--platform-url",
        help="Public URL that will host the created archive. If omitted, a placeholder is emitted.",
    )
    return parser.parse_args()


def should_skip(path: Path, repo_root: Path, output_dir: Path) -> bool:
    rel = path.relative_to(repo_root)
    parts = set(rel.parts)
    if parts & EXCLUDED_DIRS:
        return True
    if path.name in EXCLUDED_FILES:
        return True
    try:
        path.relative_to(output_dir)
        return True
    except ValueError:
        return False


def iter_files(repo_root: Path, output_dir: Path):
    for path in sorted(repo_root.rglob("*")):
        if not path.is_file():
            continue
        if should_skip(path, repo_root, output_dir):
            continue
        yield path


def create_archive(repo_root: Path, output_dir: Path, package_name: str, version: str) -> Path:
    output_dir.mkdir(parents=True, exist_ok=True)
    archive_name = f"{package_name}-{version}.zip"
    archive_path = output_dir / archive_name
    prefix = f"{package_name}-{version}"

    with zipfile.ZipFile(archive_path, "w", compression=zipfile.ZIP_DEFLATED) as zf:
        for path in iter_files(repo_root, output_dir):
            rel = path.relative_to(repo_root)
            zf.write(path, arcname=str(Path(prefix) / rel))

    return archive_path


def sha256_file(path: Path) -> str:
    digest = sha256()
    with path.open("rb") as fh:
        for chunk in iter(lambda: fh.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest().upper()


def semver_key(version: str):
    parts = re.split(r"[.-]", version)
    key = []
    for part in parts:
        if part.isdigit():
            key.append((0, int(part)))
        else:
            key.append((1, part))
    return tuple(key)


def load_latest_dependencies(index_path: Path):
    if not index_path.exists():
        return DEFAULT_DEPENDENCIES
    try:
        data = json.loads(index_path.read_text(encoding="utf-8"))
        platforms = data["packages"][0]["platforms"]
    except (KeyError, IndexError, json.JSONDecodeError):
        return DEFAULT_DEPENDENCIES

    latest = max(platforms, key=lambda item: semver_key(item.get("version", "0")))
    return latest.get("toolsDependencies", DEFAULT_DEPENDENCIES)


def read_board_names(boards_txt: Path):
    names = []
    pattern = re.compile(r"^[^.]+\.name=(.+)$")
    for line in boards_txt.read_text(encoding="utf-8").splitlines():
        match = pattern.match(line)
        if not match:
            continue
        names.append({"name": f"{match.group(1).strip()} EVT Board"})
    return names


def platform_uses_wchisp(platform_txt: Path) -> bool:
    return "runtime.tools.wchisp.path" in platform_txt.read_text(encoding="utf-8")


def build_platform_entry(version: str, archive_path: Path, platform_url: str, boards, tools_dependencies):
    return {
        "name": "CH32 MCU EVT Boards",
        "architecture": "ch32v",
        "version": version,
        "category": "Contributed",
        "url": platform_url,
        "archiveFileName": archive_path.name,
        "checksum": f"SHA-256:{sha256_file(archive_path)}",
        "size": str(archive_path.stat().st_size),
        "boards": boards,
        "toolsDependencies": tools_dependencies,
    }


def main() -> int:
    args = parse_args()
    repo_root = args.repo_root.resolve()
    output_dir = args.output_dir.resolve()

    boards_txt = repo_root / "boards.txt"
    platform_txt = repo_root / "platform.txt"
    index_path = repo_root / "package_ch32v_index.json"

    missing = [str(path) for path in (boards_txt, platform_txt) if not path.exists()]
    if missing:
        print("missing required files:", ", ".join(missing), file=sys.stderr)
        return 1

    archive_path = create_archive(repo_root, output_dir, args.package_name, args.version)
    platform_url = args.platform_url or f"https://example.invalid/{archive_path.name}"
    boards = read_board_names(boards_txt)
    tools_dependencies = load_latest_dependencies(index_path)
    entry = build_platform_entry(args.version, archive_path, platform_url, boards, tools_dependencies)

    print(f"archive: {archive_path}")
    print(f"sha256:  {entry['checksum']}")
    print(f"size:    {entry['size']}")
    print()
    print("package_ch32v_index.json platform entry:")
    print(json.dumps(entry, indent=2, ensure_ascii=True))
    print()

    if platform_uses_wchisp(platform_txt):
        has_wchisp_dependency = any(dep.get("name") == "wchisp" for dep in tools_dependencies)
        if not has_wchisp_dependency:
            print("note: platform.txt references wchisp, but the emitted toolsDependencies do not include it.")
            print("note: quick publishing is still possible, but ISP upload will not work until wchisp is packaged.")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
