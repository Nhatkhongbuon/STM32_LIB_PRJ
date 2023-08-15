/*
 * RingBuffer.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Admin
 */

#ifndef USER_RINGBUFFER_H_
#define USER_RINGBUFFER_H_


typedef struct
{
	char x;
	short y;
	int z;
} dataTypedef;

typedef struct
{
	char *buf;
	unsigned char sizeOfElm;
	unsigned char size; // MAX size
	unsigned char head;
	unsigned char tail;
	unsigned char count;
} ringBufferTypedef;

void ringBufferInit(ringBufferTypedef *cBuffer, void *address, unsigned char sizeOfElm, unsigned char size);
char checkFull(ringBufferTypedef *cBuffer);
char checkEmpty(ringBufferTypedef *cBuffer);
void put(ringBufferTypedef *cBuffer, void *dataIn);
void get(ringBufferTypedef *cBuffer, void *dataOut);
char putToBuffer(ringBufferTypedef *cBuffer, char dataIn);
char getFromBuffer(ringBufferTypedef *cBuffer, char *dataOut);

#endif /* USER_RINGBUFFER_H_ */
