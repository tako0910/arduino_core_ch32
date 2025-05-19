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

#include "Arduino.h"
#include "PeripheralPins.h"

/* =====
 * Notes:
 * - The CH570 peripheral pin mapping is based on the datasheet specifications
 * - CH570 uses a comparator which can act as a 4-bit ADC with 16 reference voltage levels
 * - CH570 has no true DAC, but supports PWM for analog output functions
 * - Careful attention to pin alternative functions is required when using peripherals
 * =====
 */

#ifdef HAL_ADC_MODULE_ENABLED
// ADC
const PinMap PinMap_ADC[] = {
    {PA_1,  ADC1, PIN_DATA(GPIO_AF_0, 0, 0)}, // Comparator input
    {PA_4,  ADC1, PIN_DATA(GPIO_AF_0, 1, 0)}, // Comparator input
    {PA_5,  ADC1, PIN_DATA(GPIO_AF_0, 2, 0)}, // Comparator input 
    {PA_9,  ADC1, PIN_DATA(GPIO_AF_0, 3, 0)}, // Comparator input
    {PA_12, ADC1, PIN_DATA(GPIO_AF_0, 4, 0)}, // Comparator input
    {PB_5,  ADC1, PIN_DATA(GPIO_AF_0, 5, 0)}, // Comparator input
    {NC,    NP,   0}
};
#endif

#ifdef HAL_DAC_MODULE_ENABLED
// CH570 doesn't have a true DAC, use PWM instead
const PinMap PinMap_DAC[] = {
    {NC, NP, 0}
};
#endif

#ifdef HAL_I2C_MODULE_ENABLED
// I2C SCL
const PinMap PinMap_I2C_SCL[] = {
    {PB_6,  I2C1, PIN_DATA(GPIO_AF_0, 0, 0)}, // Default I2C_SCL
    {PA_4,  I2C1, PIN_DATA(GPIO_AF_1, 1, 0)}, // Remap I2C_SCL
    {PA_1,  I2C1, PIN_DATA(GPIO_AF_2, 2, 0)}, // Remap I2C_SCL
    {PA_5,  I2C1, PIN_DATA(GPIO_AF_3, 3, 0)}, // Remap I2C_SCL
    {NC,    NP,   0}
};

// I2C SDA
const PinMap PinMap_I2C_SDA[] = {
    {PB_7,  I2C1, PIN_DATA(GPIO_AF_0, 0, 0)}, // Default I2C_SDA
    {PA_7,  I2C1, PIN_DATA(GPIO_AF_1, 1, 0)}, // Remap I2C_SDA
    {PA_2,  I2C1, PIN_DATA(GPIO_AF_2, 2, 0)}, // Remap I2C_SDA
    {PA_6,  I2C1, PIN_DATA(GPIO_AF_3, 3, 0)}, // Remap I2C_SDA
    {NC,    NP,   0}
};
#endif

#ifdef HAL_PWR_MODULE_ENABLED
// PWM
const PinMap PinMap_PWM[] = {
    {PA_4,  TIM1, PIN_DATA(GPIO_AF_1, 0, 0)}, // PWM0
    {PA_5,  TIM1, PIN_DATA(GPIO_AF_1, 1, 0)}, // PWM1
    {PA_9,  TIM2, PIN_DATA(GPIO_AF_1, 2, 0)}, // PWM2
    {PA_10, TIM2, PIN_DATA(GPIO_AF_1, 3, 0)}, // PWM3
    {PB_0,  TIM3, PIN_DATA(GPIO_AF_1, 4, 0)}, // PWM4
    {PB_4,  TIM3, PIN_DATA(GPIO_AF_1, 5, 0)}, // PWM5
    {NC,    NP,   0}
};
#endif

#ifdef HAL_SPI_MODULE_ENABLED
// SPI SCK
const PinMap PinMap_SPI_SCLK[] = {
    {PA_5, SPI1, PIN_DATA(GPIO_AF_0, 0, 0)}, // Default SPI_SCK
    {NC,   NP,   0}
};

// SPI MISO
const PinMap PinMap_SPI_MISO[] = {
    {PA_6, SPI1, PIN_DATA(GPIO_AF_0, 0, 0)}, // Default SPI_MISO
    {NC,   NP,   0}
};

// SPI MOSI
const PinMap PinMap_SPI_MOSI[] = {
    {PA_7, SPI1, PIN_DATA(GPIO_AF_0, 0, 0)}, // Default SPI_MOSI
    {NC,   NP,   0}
};

// SPI NSS (CS)
const PinMap PinMap_SPI_SSEL[] = {
    {PA_4, SPI1, PIN_DATA(GPIO_AF_0, 0, 0)}, // Default SPI_SCS
    {PA_2, SPI1, PIN_DATA(GPIO_AF_1, 1, 0)}, // Remap SPI_SCS
    {NC,   NP,   0}
};
#endif

#ifdef HAL_UART_MODULE_ENABLED
// UART RX
const PinMap PinMap_UART_RX[] = {
    {PA_10, USART1, PIN_DATA(GPIO_AF_0, 0, 0)}, // Default UART_RX
    {PA_3,  USART1, PIN_DATA(GPIO_AF_1, 1, 0)}, // Remap UART_RX
    {NC,    NP,     0}
};

// UART TX
const PinMap PinMap_UART_TX[] = {
    {PA_9, USART1, PIN_DATA(GPIO_AF_0, 0, 0)}, // Default UART_TX
    {PA_2, USART1, PIN_DATA(GPIO_AF_1, 1, 0)}, // Remap UART_TX
    {NC,   NP,     0}
};
#endif

#ifdef HAL_USB_MODULE_ENABLED
// USB
const PinMap PinMap_USB[] = {
    {PB_11, USB, PIN_DATA(GPIO_AF_0, 0, 0)}, // USB_DM
    {PB_12, USB, PIN_DATA(GPIO_AF_0, 0, 0)}, // USB_DP
    {NC,    NP,  0}
};
#endif
