/*
 * DS1307_Lib.h
 *
 *  Created on: Aug 18, 2023
 *      Author: nguyenphuminhnhat
 */

#ifndef USER_DS1307_LIB_H_
#define USER_DS1307_LIB_H_

const byte DS1307_ADDRESS = 0x68; //Address of DS1307
const byte numberOfBits = 7; //Number of bits read from DS1307
char Time[] = "Time:  :  :  ";
char Calendar[] = "DATE:  :  :20  ";

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



#endif /* USER_DS1307_LIB_H_ */
