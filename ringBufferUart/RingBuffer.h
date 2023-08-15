/*
 * RingBuffer.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Nhatkhongbuon
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
	char *buf;							// pointer to manage address of cBuffer
	unsigned char sizeOfElm;			// size of buffer
	unsigned char size; 				// size of an element in buffer
	unsigned char head;					// pointer head
	unsigned char tail;					// pointer tail
	unsigned char count;				// variable count
} ringBufferTypedef;

void ringBufferInit(ringBufferTypedef *cBuffer, void *address, unsigned char sizeOfElm, unsigned char size);
char checkFull(ringBufferTypedef *cBuffer);
char checkEmpty(ringBufferTypedef *cBuffer);
void put(ringBufferTypedef *cBuffer, void *dataIn);
void get(ringBufferTypedef *cBuffer, void *dataOut);
char putToBuffer(ringBufferTypedef *cBuffer, char dataIn);
char getFromBuffer(ringBufferTypedef *cBuffer, char *dataOut);

#endif /* USER_RINGBUFFER_H_ */
