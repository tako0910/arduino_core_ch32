#!/usr/bin/env python3

import argparse
import io
import tarfile
from hashlib import sha256
from pathlib import Path


PACKAGES = {
    "windows": {
        "archive": "wch_beforeinstall_windows_noop-1.0.0.tar.gz",
        "files": {
            "README.txt": (
                "This is a no-op beforeinstall package for Windows.\n"
                "No post-install action is required on this platform.\n"
            ),
            "start.bat": (
                "@echo off\r\n"
                "echo No post-install action is required on Windows.\r\n"
            ),
        },
    },
    "macos": {
        "archive": "wch_beforeinstall_macos_noop-1.0.0.tar.gz",
        "files": {
            "README.txt": (
                "This is a no-op beforeinstall package for macOS.\n"
                "No post-install script is required.\n"
                "Install libusb manually if upload tools need it.\n"
            ),
            "start.sh": (
                "#!/bin/sh\n"
                "echo 'No post-install action is required on macOS.'\n"
                "echo 'If needed, install libusb with: brew install libusb'\n"
            ),
        },
    },
}


def parse_args():
    parser = argparse.ArgumentParser(
        description="Build no-op beforeinstall archives for non-Linux hosts."
    )
    parser.add_argument(
        "--output-dir",
        default=Path(__file__).resolve().parents[1] / "dist",
        type=Path,
        help="Directory where the archives will be written.",
    )
    return parser.parse_args()


def add_bytes(tar: tarfile.TarFile, name: str, data: bytes, mode: int):
    info = tarfile.TarInfo(name=name)
    info.size = len(data)
    info.mode = mode
    tar.addfile(info, io.BytesIO(data))


def add_directory(tar: tarfile.TarFile, name: str, mode: int = 0o755):
    info = tarfile.TarInfo(name=name.rstrip("/") + "/")
    info.type = tarfile.DIRTYPE
    info.mode = mode
    tar.addfile(info)


def sha256_file(path: Path) -> str:
    digest = sha256()
    with path.open("rb") as fh:
        for chunk in iter(lambda: fh.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest().upper()


def build_archive(output_dir: Path, archive_name: str, files: dict[str, str]) -> Path:
    output_dir.mkdir(parents=True, exist_ok=True)
    archive_path = output_dir / archive_name
    root_dir = archive_name[:-7] if archive_name.endswith(".tar.gz") else Path(archive_name).stem
    with tarfile.open(archive_path, "w:gz") as tar:
        add_directory(tar, root_dir)
        for name, text in files.items():
            mode = 0o755 if name.endswith((".sh", ".bat", ".command")) else 0o644
            add_bytes(tar, f"{root_dir}/{name}", text.encode("utf-8"), mode)
    return archive_path


def main():
    args = parse_args()
    for host, package in PACKAGES.items():
        archive_path = build_archive(args.output_dir, package["archive"], package["files"])
        print(f"{host}:")
        print(f"  archive:  {archive_path}")
        print(f"  sha256:   SHA-256:{sha256_file(archive_path)}")
        print(f"  size:     {archive_path.stat().st_size}")


if __name__ == "__main__":
    main()
