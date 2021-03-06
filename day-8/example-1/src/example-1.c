/*
 ============================================================================
 Name        : example-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "CircularBuffer.h"

int main(void) {

	circular_buffer buffer;
	CircularInit(&buffer);
	if (CircularIsEmpty(&buffer))
		printf("Bafer je prazan\n");

	CircularPut(&buffer, 21);
	CircularPut(&buffer, 25);
	CircularPut(&buffer, 41);
	CircularPut(&buffer, 25);
	CircularPut(&buffer, 41);
	CircularPut(&buffer, 25);
	CircularPut(&buffer, 41);
	CircularPut(&buffer, 25);
	CircularPut(&buffer, 41);
	if (CircularIsFull(&buffer))
		printf("\nBafer je pun\n");

	CircularDump(&buffer);
	//CircularEmptyBuff(&buffer);
	return 0;
}
