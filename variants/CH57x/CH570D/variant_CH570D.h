/*
 *******************************************************************************
 * Custom implementation for CH570/CH572 microcontroller family
 * Based on the CH570/CH572 datasheet and reference manual
 *
 * Licensed under the BSD 3-Clause License
 * You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */

#ifndef _VARIANT_CH570D_H_
#define _VARIANT_CH570D_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Digital PinName array
extern const PinName digitalPin[];
// Analog (ADC) PinName array
extern const PinName analogInputPin[];
// PWM PinName array
extern const PinName analogOutputPin[];

// Enum defining pin names to which user can refer
enum {
  PA0,  PA1,  PA2,  PA3,  PA4,  PA5,  PA6,  PA7,
  PA8,  PA9,  PA10, PA11, PA12, PA13, PA14, PA15,
  PB0,  PB1,  PB2,  PB3,  PB4,  PB5,  PB6,  PB7,
  PB8,  PB9,  PB10, PB11, PB12, PB13, PB14, PB15,
  PC0,
  NUM_DIGITAL_PINS,
  
  // Alias for analog input
  A0 = PA1,  // Comparator input (equivalent to 4-bit ADC)
  A1 = PA4,
  A2 = PA5,
  A3 = PA9,
  A4 = PA12,
  A5 = PB5,
  
  // LED definitions
  LED1 = PB19,
  LED_BUILTIN = LED1,
  
  // Communication interfaces
  UART_TX = PA9,
  UART_RX = PA10,
  
  SPI_MOSI = PA7,
  SPI_MISO = PA6,
  SPI_SCK = PA5,
  SPI_SS = PA4,
  
  I2C_SCL = PB6,
  I2C_SDA = PB7,
  
  // USB pins
  USB_DM = PB11,
  USB_DP = PB12,
};

// Digital I/O
#define PIN_SPI_SS              SPI_SS
#define PIN_SPI_MOSI            SPI_MOSI
#define PIN_SPI_MISO            SPI_MISO
#define PIN_SPI_SCK             SPI_SCK

#define PIN_WIRE_SDA            I2C_SDA
#define PIN_WIRE_SCL            I2C_SCL

#define PIN_UART_RX             UART_RX
#define PIN_UART_TX             UART_TX

#define digitalPinToPort(p)     (digitalPin[p].port)
#define digitalPinToBitMask(p)  (digitalPin[p].pinMask)

// ADC resolution is 4 bits (via comparator)
#define ADC_RESOLUTION          4
#define DACC_RESOLUTION         0 // CH570 does not have true DAC

// PWM resolution
#define PWM_RESOLUTION          16
#define PWM_FREQUENCY           1000
#define PWM_MAX_DUTY_CYCLE      ((1 << PWM_RESOLUTION) - 1)

// SPI definitions
#define PIN_SPI_SS1             PA4
#define PIN_SPI_MOSI1           PA7
#define PIN_SPI_MISO1           PA6
#define PIN_SPI_SCK1            PA5

// I2C definitions
#define PIN_WIRE_SDA1           PB7
#define PIN_WIRE_SCL1           PB6

// Timer definitions
#define TIMER_TONE              TIM2
#define TIMER_SERVO             TIM3

// UART definitions
#define SERIAL_UART_INSTANCE    1

// Default pin used for 'Serial' instance
#define PIN_SERIAL_RX           PA10
#define PIN_SERIAL_TX           PA9

// Extra HAL modules
#define HAL_DAC_MODULE_ENABLED
#define HAL_I2C_MODULE_ENABLED
#define HAL_SPI_MODULE_ENABLED
#define HAL_UART_MODULE_ENABLED
#define HAL_USB_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED
#define HAL_EXTI_MODULE_ENABLED
#define HAL_PWR_MODULE_ENABLED
#define HAL_RTC_MODULE_ENABLED

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

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
  // SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
  //
  // SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
  //                            pins are NOT connected to anything by default.
  #ifndef SERIAL_PORT_MONITOR
    #define SERIAL_PORT_MONITOR   Serial
  #endif
  #ifndef SERIAL_PORT_HARDWARE
    #define SERIAL_PORT_HARDWARE  Serial1
  #endif
#endif

#endif /* _VARIANT_CH570D_H_ */
