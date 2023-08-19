/*
 *
 */
#include "DS1307_Lib.h"

/**
  * @brief  Convert BCD number to Decimal number and conversely
  * @param  num: number want to convert
  * @retval(return value) number after convert
  */
static uint8_t BCD2DEC(uint8_t num)
{
	return ((num >> 4) * 10 + (num & 0x0F));
}

static uint8_t DEC2BCD(uint8_t num)
{
	return (((num / 10) << 4) + (num % 10));
}

/**
  * @brief  Write and Read function to rom of DS1307
  * @param  DS1307_Name* DS1307: Pointer of typedef struct DS1307
  * @retval Data is received is stored in RxBuffer, Transfer data in TxBuffer to Rom of Ds1307
  */

static void I2C_WriteTime(DS1307_Name* DS1307)
{
	HAL_I2C_Mem_Write_DMA(DS1307->I2C, 0x68, 0, I2C_MEMADD_SIZE_8BIT, DS1307->TxTimeBuff, 1000);
}

static void I2C_ReadTime(DS1307_Name* DS1307)
{
	HAL_I2C_Mem_Read_DMA(DS1307->I2C, 0x68, 0, I2C_MEMADD_SIZE_8BIT, DS1307->RxTimeBuff, 1000);
}

static void I2C_WriteDate(DS1307_Name* DS1307)
{
	HAL_I2C_Mem_Write_DMA(DS1307->I2C, 0x68, 3, I2C_MEMADD_SIZE_8BIT, DS1307->TxDateBuff, 1000);
}

static void I2C_ReadDate(DS1307_Name* DS1307)
{
	HAL_I2C_Mem_Read_DMA(DS1307->I2C, 0x68, 3, I2C_MEMADD_SIZE_8BIT, DS1307->RxDateBuff, 1000);
}


/**
  * @brief  Init Module DS1307
  * @param  DS1307_Name* DS1307: Pointer of typedef struct DS1307
  * @param 	I2C_HandleTypeDef* I2CInit: Pointer of I2C------ ex: &hi2c1
  */
void DS1307_Init(DS1307_Name* DS1307, I2C_HandleTypeDef* I2CInit)
{
	DS1307->I2C = I2CInit;
}
/**
  * @brief  Convert BCD number to Decimal number and conversely
  * @param  num: number want to convert
  * @retval(return value) number after convert
  */

void DS1307_SetTime(DS1307_Name* DS1307, uint8_t Hour, uint8_t Min, uint8_t Sec)
{
	DS1307->TxTimeBuff[0] = DEC2BCD(Hour);
	DS1307->TxTimeBuff[1] = DEC2BCD(Min);
	DS1307->TxTimeBuff[2] = DEC2BCD(Sec);
	I2C_WriteTime(DS1307);
}

void DS1307_GetTime(DS1307_Name* DS1307)
{
	I2C_ReadTime(DS1307);
	DS1307->Sec = BCD2DEC(DS1307->RxTimeBuff[0]);
	DS1307->Min = BCD2DEC(DS1307->RxTimeBuff[1]);
	DS1307->Hour = BCD2DEC(DS1307->RxTimeBuff[2]);
}

void DS1307_SetDate(DS1307_Name* DS1307, uint8_t Day, uint8_t Date, uint8_t Month, uint8_t Year)
{
	DS1307->TxDateBuff[0] = DEC2BCD(Day);
	DS1307->TxDateBuff[1] = DEC2BCD(Date);
	DS1307->TxDateBuff[2] = DEC2BCD(Month);
	DS1307->TxDateBuff[3] = DEC2BCD(Year);
	I2C_WriteDate(DS1307);
}

void DS1307_GetDate(DS1307_Name* DS1307)
{
	I2C_ReadDate(DS1307);
	DS1307->Day = BCD2DEC(DS1307->RxDateBuff[0]);
	DS1307->Date = BCD2DEC(DS1307->RxDateBuff[1]);
	DS1307->Month = BCD2DEC(DS1307->RxDateBuff[2]);
	DS1307->Year = BCD2DEC(DS1307->RxDateBuff[3]);
}



























