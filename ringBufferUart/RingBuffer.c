/*
 * RingBuffer.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Nhatkhongbuon
 */

#include "Ringbuffer.h"

/*
	Cbuffer: manage the new ring buffer is created
	address: address of buffer use to ring buffer
	sizeOfElm: size of an element in buffer 
*/
void ringBufferInit(ringBufferTypedef *cBuffer, void *address, unsigned char sizeOfElm, unsigned char size)
{

	cBuffer->buf = (char*)address;     
	cBuffer->size = size;				
	cBuffer->sizeOfElm = sizeOfElm;		
	cBuffer->head = 0;					
	cBuffer->tail = 0;					
	cBuffer->count = 0;					
}

/*
	functions to check buffer is full or empty?
*/
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

/*
	fucntions to add new data to head position and get data from tail position
*/
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
/*
	function put data to buffer after check full buffer
*/
char putToBuffer(ringBufferTypedef *cBuffer, char dataIn)
{
	if(checkFull(cBuffer) == 1) return 0;
	put(cBuffer, dataIn);
	return 1;
}
/*
	function get data form buffer after check empty buffer
*/
char getFromBuffer(ringBufferTypedef *cBuffer, char *dataOut)
{
	if(checkEmpty(cBuffer) == 1) return 0;
	get(cBuffer, dataOut);
	return 1;
}
