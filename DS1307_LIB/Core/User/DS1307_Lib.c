/*
 *
 */


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
  * @brief  Init Module DS1307
  * @param  DS1307_Name* DS1307: Pointer of typedef struct DS1307
  * @param 	I2C_HandleTypeDef* I2CInit: Pointer of I2C------ ex: &hi2c1
  */
void DS1307_Init(DS1307_Name* DS1307, I2C_HandleTypeDef* I2CInit)
{
	DS1307->I2C = I2CInit;
}

/**
  * @brief  Write and Read function to rom of DS1307
  * @param  DS1307_Name* DS1307: Pointer of typedef struct DS1307
  * @retval Data is received is stored in RxBuffer, Transfer data in TxBuffer to Rom of Ds1307
  */

static void I2C_WriteTime(DS1307_Name* DS1307)
{
	HAL_I2C_Mem_Write_DMA(DS1307->I2C, DS1307_ADDRESS, 0, numberOfBits, DS1307->TxTimeBuff, 3, 1000);
}

static void I2C_ReadTime(DS1307_Name* DS1307)
{
	HAL_I2C_Mem_Read_DMA(DS1307->I2C, DS1307_ADDRESS, 0, numberOfBits, DS1307->RxTimeBuff, 3, 1000);
}

static void I2C_WriteDate(DS1307_Name* DS1307)
{
	HAL_I2C_Mem_Write_DMA(DS1307->I2C, DS1307_ADDRESS, 3, numberOfBits, DS1307->TxDateBuff, 4, 1000);
}

static void I2C_ReadDate(DS1307_Name* DS1307)
{
	HAL_I2C_Mem_Read_DMA(DS1307->I2C, DS1307_ADDRESS, 3, numberOfBits, DS1307->RxDateBuff, 4, 1000);
}




