#include "pins_arduino.h"

// Digital PinName array
const PinName digitalPin[] = {
  NC,    // D0 not routed
  PA_1,  // D1/A1
  PA_2,  // D2/A0
  PA_3,  // D3
  PA_4,  // D4
  PA_5,  // D5
  NC,    // D6 not routed
  NC,    // D7 not routed
  NC,    // D8 not routed
  NC,    // D9 not routed
  NC,    // D10 not routed
  NC,    // D11 not routed
  NC,    // D12 not routed
  NC,    // D13 not routed
  NC,    // D14 not routed
  PC_0,  // D15
  PC_1,  // D16/SDA
  PC_2,  // D17/SCL
  PC_3,  // D18/LED
  PC_4,  // D19/A2
  PC_5,  // D20/SCK
  PC_6,  // D21/MOSI
  PC_7,  // D22/MISO
  PD_0,  // D23
  PD_1,  // D24/SWIO
  PD_2,  // D25/A3
  NC,    // D26 not routed
  NC,    // D27 not routed
  PD_5,  // D28/TX/A5
  PD_6,  // D29/RX/A6
  PD_7,  // D30
};

// Analog (Ax) pin number array
const uint32_t analogInputPin[] = {
  2,                // A0/D2
  1,                // A1/D1
  19,               // A2/D19
  25,               // A3/D25
  PNUM_NOT_DEFINED, // A4 not routed
  28,               // A5/D28
  29,               // A6/D29
};
