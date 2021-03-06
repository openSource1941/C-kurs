/*
 ============================================================================
 Name        : example-4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>

#define FILE_NAME "binaryFile.dat"


typedef struct _example_struct
{
	char   char_1;
	char   char_2;
	short ssInt_2;
	unsigned int uInt_1;
	int  sInt_3;
	char char_3;
} example_struct;


void dumpExampleStruct(example_struct* es);

int main()
{
	FILE* file;
	example_struct eStruct;

	char str[20] = "Test string";
	unsigned int uInt_1 = 22;
	short ssInt_2 = 333;
	int sInt_3 = 4444;

	printf("Writing to binary file %s\n", FILE_NAME);
	file = fopen(FILE_NAME, "wb");
	if (file != NULL)
	{
		fwrite(str, 1, sizeof(char), file);
		fwrite(str + 1, 1, sizeof(char), file);
		fwrite(&ssInt_2, 1, sizeof(short), file);
		fwrite(&uInt_1, 1, sizeof(int), file);
		fwrite(&sInt_3, 1, sizeof(int), file);
		fwrite(str + 2, 1, sizeof(char), file);
		fclose(file);
		file = NULL;
	}

	printf("\n%d",sizeof(example_struct));
	printf("Reading struct from binary file %s\n", FILE_NAME);
	file = fopen(FILE_NAME, "rb");
	if (file != NULL)
	{
		fread(&eStruct, 1, sizeof(example_struct), file);

		dumpExampleStruct(&eStruct);
		fclose(file);
		file = NULL;
	}

	return 1;
}

void dumpExampleStruct(example_struct* es)
{
	printf("example_struct\n");
	printf("  char_1 = %c\n", es->char_1);
	printf("  char_2 = %c\n", es->char_2);
	printf("  uInt_1 = %d\n", es->uInt_1);
	printf("  ssInt_2 = %d\n", es->ssInt_2);
	printf("  sInt_3 = %d\n", es->sInt_3);
	printf("  char_3 = %c\n", es->char_3);
	printf("\n");
}

