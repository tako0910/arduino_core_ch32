#pragma once

/* ENABLE Peripherals */
#define                         ADC_MODULE_ENABLED
#define                         UART_MODULE_ENABLED
#define                         SPI_MODULE_ENABLED
#define                         I2C_MODULE_ENABLED
#define                         TIM_MODULE_ENABLED

/* UIAPduino Pro Micro CH32V006 V1.1 pins */
#define PA0                     PNUM_NOT_DEFINED
#define PA1                     PIN_A1
#define PA2                     PIN_A0
#define PA3                     3
#define PA4                     4
#define PA5                     5
#define PA6                     PNUM_NOT_DEFINED
#define PA7                     PNUM_NOT_DEFINED
#define PB0                     PNUM_NOT_DEFINED
#define PB1                     PNUM_NOT_DEFINED
#define PB2                     PNUM_NOT_DEFINED
#define PB3                     PNUM_NOT_DEFINED
#define PB4                     PNUM_NOT_DEFINED
#define PB5                     PNUM_NOT_DEFINED
#define PB6                     PNUM_NOT_DEFINED
#define PC0                     15
#define PC1                     16
#define PC2                     17
#define PC3                     18
#define PC4                     PIN_A2
#define PC5                     20
#define PC6                     21
#define PC7                     22
#define PD0                     23
#define PD1                     24
#define PD2                     PIN_A3
#define PD3                     PNUM_NOT_DEFINED
#define PD4                     PNUM_NOT_DEFINED
#define PD5                     PIN_A5
#define PD6                     PIN_A6
#define PD7                     30

// Alternate pins number
#define PD5_ALT1                (PD5 | ALT1)
#define PD6_ALT1                (PD6 | ALT1)


#define NUM_DIGITAL_PINS        31
#define NUM_ANALOG_INPUTS       7

// #define ADC_CTLR_ADCAL
#define ADC_RESOLUTION          12


// On-board LED pin number
#ifndef LED_BUILTIN
  #define LED_BUILTIN           PC3
#endif


// On-board user button
#ifndef USER_BTN
  #define USER_BTN              PNUM_NOT_DEFINED
#endif


// UART Definitions
#ifndef SERIAL_UART_INSTANCE
  #define SERIAL_UART_INSTANCE  1
#endif
// Default pin used for generic 'Serial' instance
// Mandatory for Firmata
#ifndef PIN_SERIAL_RX
  #define PIN_SERIAL_RX         PD6
#endif
#ifndef PIN_SERIAL_TX
  #define PIN_SERIAL_TX         PD5
#endif


// SPI definitions
#ifndef PIN_SPI_SS
  #define PIN_SPI_SS            PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_SS1
  #define PIN_SPI_SS1           PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_SS2
  #define PIN_SPI_SS2           PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_SS3
  #define PIN_SPI_SS3           PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_MOSI
  #define PIN_SPI_MOSI          PC6
#endif
#ifndef PIN_SPI_MISO
  #define PIN_SPI_MISO          PC7
#endif
#ifndef PIN_SPI_SCK
  #define PIN_SPI_SCK           PC5
#endif

// I2C definitions
#ifndef PIN_WIRE_SDA
  #define PIN_WIRE_SDA          PC1
#endif
#ifndef PIN_WIRE_SCL
  #define PIN_WIRE_SCL          PC2
#endif

#ifndef TIMER_TONE
  #define TIMER_TONE            TIM2
#endif
#ifndef TIMER_SERVO
  #define TIMER_SERVO           TIM1
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
  // These serial port names are intended to allow libraries and architecture-neutral
  // sketches to automatically default to the correct port name for a particular type
  // of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
  // the first hardware serial port whose RX/TX pins are not dedicated to another use.
  //
  // SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
  //
  // SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
  //
  // SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
  //
  // SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
  //
  // SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
  //                            pins are NOT connected to anything by default.
  #ifndef SERIAL_PORT_MONITOR
    #define SERIAL_PORT_MONITOR   Serial
  #endif
  #ifndef SERIAL_PORT_HARDWARE
    #define SERIAL_PORT_HARDWARE  Serial
  #endif
#endif
