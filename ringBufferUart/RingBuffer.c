/*
 * RingBuffer.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Admin
 */

#include "Ringbuffer.h"


void ringBufferInit(ringBufferTypedef *cBuffer, void *address, unsigned char sizeOfElm, unsigned char size)
{

	cBuffer->buf = (char*)address;
	cBuffer->size = size;
	cBuffer->sizeOfElm = sizeOfElm;
	cBuffer->head = 0;
	cBuffer->tail = 0;
	cBuffer->count = 0;
}

char checkFull(ringBufferTypedef *cBuffer)
{
	if(cBuffer->count == cBuffer->size) return 1;
	return 0;
}

char checkEmpty(ringBufferTypedef *cBuffer)
{
	if(cBuffer->count == 0) return 1;
	return 0;
}

void put(ringBufferTypedef *cBuffer, void *dataIn)
{
	unsigned char i;
	char *p = (char*)&cBuffer->buf[cBuffer->sizeOfElm*cBuffer->head];
	char *q = (char*)dataIn;

	for(i=0; i<cBuffer->sizeOfElm; i++) p[i] = q[i];

	cBuffer->head = (cBuffer->head+1) % cBuffer->size;
	cBuffer->count++;
}

void get(ringBufferTypedef *cBuffer, void *dataOut)
{
	unsigned char i;
	char *p = (char*)dataOut;
	char *q = (char*)&cBuffer->buf[cBuffer->sizeOfElm*cBuffer->tail];

	for(i=0; i<cBuffer->sizeOfElm; i++) p[i] = q[i];

	cBuffer->tail = (cBuffer->tail+1) % cBuffer->size;
	cBuffer->count--;
}

char putToBuffer(ringBufferTypedef *cBuffer, char dataIn)
{
	if(checkFull(cBuffer) == 1) return 0;
	put(cBuffer, dataIn);
	return 1;
}

char getFromBuffer(ringBufferTypedef *cBuffer, char *dataOut)
{
	if(checkEmpty(cBuffer) == 1) return 0;
	get(cBuffer, dataOut);
	return 1;
}
