#ifndef __SPI_H
#define __SPI_H
#include "marco.h"


//extern SPI_HandleTypeDef SPI5_Handler;

void SPI5_Init(void);
void SPI1_Init(void);
void SPI5_SetSpeed(u8 SPI_BaudRatePrescaler);
u8 SPI5_ReadWriteByte(u8 TxData);
u8 SPI1_ReadWriteByte(u8 TxData);
void SPI5_MCU1_TEST(void);
void SPI5_MCU2_TEST(void);
void SPI1_MCU1_TEST(void);
int SPI2_MCU1_TEST(void);
int SPI2_MCU1_CONF_READ_TEST(uint8_t addr,uint8_t value);
void SPI2_MCU1_CONF_WRITE_TEST(uint8_t addr,uint8_t value);
#endif
