#include <stdio.h>
#include <stdlib.h>

extern int sumAsm(int, int);
extern void printMessage();

int main()
{
	int a =10;
	int b = 3;
	int c = 0;

	printf("=============================================\n");
	printf("Exercise1 - Embedded functions  \n");
	printf("=============================================\n");

	// Embedding assembly code - xor swap function
	asm(" \
		xor  %%rbx, %%rax; \
		xor  %%rax, %%rbx; \
		xor  %%rbx, %%rax; "
		:"=a"(a), "=b"(b)
		:"a"(a), "b"(b)
		);
	printf("values of variables after xor swap function\n");
	printf("a = %d, b = %d, c = %d \n", a, b, c);

	printf("=============================================\n");

	// Embedding assembly code - c = a + b
	printf("values of variables after adding\n");
	asm ("add  %%rbx, %%rax"
		:"=a"(c)
		:"a"(a), "b"(b)
	);
	printf("a = %d, b = %d, c = %d\n\n",a, b,c);
	printf("=============================================\n");

	// calling assembly function with parameters
	a = 0x10;
	b = 0x20;
	c = sumAsm(a, b);
	printf("values of variables after sumAsm function call\n");
	printf("a = %d, b = %d, c = %d\n\n",a, b,c);
	printf("=============================================\n");

	// calling assembly function without paramaters
	printf("printMessage function call       \n");

	printMessage();

	return 0;
}
