#ifndef UTIL_DELAY_H
#define UTIL_DELAY_H

#include <Arduino.h>

static inline void _delay_ms(double ms) {
  if (ms <= 0) {
    return;
  }
  delay((uint32_t)ms);
}

static inline void _delay_us(double us) {
  if (us <= 0) {
    return;
  }
  delayMicroseconds((uint32_t)us);
}

#endif
