#ifndef _WIRING_PRIVATE_H_
#define _WIRING_PRIVATE_H_

#include "Arduino.h"

// Minimal compatibility layer for libraries that unconditionally include
// wiring_private.h outside SAMD-style cores.
typedef uint32_t pin_size_t;

typedef enum _EPioType {
  PIO_NOT_A_PIN = 0,
  PIO_EXTINT,
  PIO_ANALOG,
  PIO_SERCOM,
  PIO_SERCOM_ALT,
  PIO_TIMER,
  PIO_TIMER_ALT,
  PIO_OUTPUT,
  PIO_INPUT
} EPioType;

static inline int pinPeripheral(pin_size_t pin, EPioType peripheral)
{
  if (!digitalPinIsValid(pin)) {
    return 0;
  }

  if (peripheral == PIO_OUTPUT) {
    pinMode(pin, OUTPUT);
  } else if (peripheral == PIO_INPUT) {
    pinMode(pin, INPUT);
  }

  return 1;
}

#endif
