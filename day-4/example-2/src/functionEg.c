#include "functionEg.h"


long factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n*factorial(n-1) ;
}

long fibonacci(long n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fibonacci(n-1)+fibonacci(n-2);
}


int staticInFunction()
{
	static int i = 0;
	i++;
	{
		int j = 0;
		j = 5%i;
		i += j;

	}
	return i;
}

long factorial_no_recursion(int n)
{
	int result = 1;
	for (int i = n; i > 0; i-- )
	{
		result *= i;
	}
	return result;
}

long fibonacci_no_recursion(long n)
{
	int fib_array[n+2];
	fib_array[0] = 0;
	fib_array[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		fib_array[i] = fib_array[i-1] + fib_array[i-2];
	}
	return fib_array[n];
	//For saving some space and using only two temporary variables, we can
	//use this method
/*
	int temp1 = 0, temp2 = 1, fib;
	if( n == 0)
        return temp1;
    for(int i = 2; i <= n; i++)
    {
       fib = temp1 + temp2;
       temp1 = temp2;
       temp2 = fib;
    }
    return temp2;
*/
}
