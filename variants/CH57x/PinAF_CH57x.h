/*
 *******************************************************************************
 * Copyright (c) 2024, WCH
 * All rights reserved.
 *
 * This software component is licensed by WCH under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _PINAF_CH57X_H
#define _PINAF_CH57X_H

#ifdef __cplusplus
extern "C" {
#endif

/* CH57x PIN AF */
/* GPIO AF values for CH570/CH572 */
typedef enum {
  GPIO_AF_0  = (0x00U),  /* Default mode */
  GPIO_AF_1  = (0x01U),  /* Alternate function */
  GPIO_AF_2  = (0x02U),  /* Alternate function */
  GPIO_AF_3  = (0x03U),  /* Alternate function */
} GPIO_AF_TypeDef;

/* Peripheral Pin Remap */
/* UART pin remap */
#define UART_PIN_DEFAULT      (0x00U)  /* Default mapping: UART1_TX/PA9, UART1_RX/PA10 */
#define UART_PIN_REMAP1       (0x01U)  /* Remap: UART1_TX/PA2, UART1_RX/PA3 */

/* SPI pin remap */
#define SPI_PIN_DEFAULT       (0x00U)  /* Default mapping: SPI_SCK/PA5, SPI_MISO/PA6, SPI_MOSI/PA7, SPI_SCS/PA4 */
#define SPI_PIN_REMAP1        (0x01U)  /* Remap: SPI_SCS/PA2 */

/* I2C pin remap */
#define I2C_PIN_DEFAULT       (0x00U)  /* Default mapping: I2C_SCL/PB6, I2C_SDA/PB7 */
#define I2C_PIN_REMAP1        (0x01U)  /* Remap: I2C_SCL/PA4, I2C_SDA/PA7 */
#define I2C_PIN_REMAP2        (0x02U)  /* Remap: I2C_SCL/PA1, I2C_SDA/PA2 */
#define I2C_PIN_REMAP3        (0x03U)  /* Remap: I2C_SCL/PA5, I2C_SDA/PA6 */

#ifdef __cplusplus
}
#endif

#endif /* _PINAF_CH57X_H */
