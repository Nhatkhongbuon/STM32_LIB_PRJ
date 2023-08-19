/*
 * DS1307_Lib.h
 *
 *  Created on: Aug 18, 2023
 *      Author: nguyenphuminhnhat
 */

#ifndef USER_DS1307_LIB_H_
#define USER_DS1307_LIB_H_

#include "stm32f1xx_hal.h"

typedef struct
{
	I2C_HandleTypeDef* I2C;
	uint8_t TxTimeBuff[3];
	uint8_t RxTimeBuff[3];
	uint8_t TxDateBuff[4];
	uint8_t RxDateBuff[4];
	uint8_t Hour;
	uint8_t Min;
	uint8_t Sec;
	uint8_t Date;
	uint8_t Day;
	uint8_t Month;
	uint8_t Year;
} DS1307_Name;

void DS1307_Init(DS1307_Name* DS1307, I2C_HandleTypeDef* I2CInit);
void DS1307_SetTime(DS1307_Name* DS1307, uint8_t Hour, uint8_t Min, uint8_t Sec);
void DS1307_GetTime(DS1307_Name* DS1307);
void DS1307_SetDate(DS1307_Name* DS1307, uint8_t Day, uint8_t Date, uint8_t Month, uint8_t Year);
void DS1307_GetDate(DS1307_Name* DS1307);

#endif /* USER_DS1307_LIB_H_ */
