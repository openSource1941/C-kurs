/*
 * CircularBuffer.c
 *
 *  Created on: Feb 15, 2022
 *      Author: sgojkovic
 */
#include "CircularBuffer.h"




void CircularInit(circular_buffer* c_buffer)
{
	c_buffer->max_len = MAX_LENGHT;
	c_buffer->size = sizeof(TYPE);
	c_buffer->buffer = (TYPE*)malloc(c_buffer->size * c_buffer->max_len);
	c_buffer->head = c_buffer->buffer;
	c_buffer->tail = c_buffer->buffer;

}


int CircularIsFull(circular_buffer* c_buffer)
{
	if((c_buffer->head - c_buffer->tail) == (c_buffer->size * (c_buffer->max_len-1)))
		return 1;
	else
		return 0;

}

int CircularIsEmpty(circular_buffer* c_buffer)
{
	if(c_buffer->head == c_buffer->tail)
		return 1;
	else
		return 0;
}


void CircularPut(circular_buffer* c_buffer,TYPE data)
{
	c_buffer->buffer = c_buffer->head;
	*c_buffer->buffer = data;
	c_buffer->head = c_buffer->head + c_buffer->size;

}

TYPE CircularGet(circular_buffer* c_buffer)
{
	TYPE a;
	a = *c_buffer->tail;
	c_buffer->tail = c_buffer->tail + c_buffer->size;
	return a;
}

void CircularEmptyBuff(circular_buffer* c_buffer)
{
	free(c_buffer->buffer);
}

void CircularDump(circular_buffer* c_buffer)
{
	for(int i=0 ; i < (c_buffer->size*c_buffer->max_len)-c_buffer->size; i = i + c_buffer->size)
		printf("%d ", CircularGet(c_buffer));
}
