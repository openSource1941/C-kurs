#include <stdio.h>
#include <stdint.h>


/*
static const int_least32_t threshold = 20;

static int_least32_t values[4000]; //when using global variables
static uint_least16_t indexes[4000]; //when using global variables
static int_least16_t indexes_of_even_values[4000]; //when using global variables
static int_least32_t even_values[4000]; //when using global variables
static int k;//when using global variables
static uint_least16_t n; //when using global variables
*/


//sorting values up to threshold
static void sort(int_least32_t* values,uint_least16_t* indexes, const uint_least16_t n)
{
	uint_least16_t i;
	uint_least16_t j;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (values[i] < values[j])
			{
				int_least32_t tmp;
				uint_least16_t tmp1;

				tmp = values[i];
				values[i] = values[j];
				values[j] = tmp;

				tmp1 = indexes[i];
				indexes[i] = indexes[j];
				indexes[j] = tmp1;
			}
		}
	}
}

//All even numbers smaller than threshold when using global variables
//static void even_numbers()
static uint_least16_t even_numbers( int_least32_t* values,uint_least16_t* indexes,  int_least32_t* even_values,  uint_least16_t* indexes_of_even_values, const uint_least16_t n, const int_least32_t threshold)
{
	uint_least16_t k = 0;
	for (int i = 0 ; i < n; i++)
	{
		if(values[i]<threshold && values[i]%2 == 0)
		{
			indexes_of_even_values[k] = indexes[i];
			even_values[k] = values[i];
			printf("%d(%d) ", values[i], indexes[i]);
			k++;
		}

	}
	printf("\n");
	return k;
}


static void print(const int_least32_t* values, const uint_least16_t* indexes, const uint_least16_t n, const int_least32_t threshold)
//static void print() //when using global variables;
{
	uint_least16_t i = 0;
	printf("Up to the first threshold: ");

	while (values[i] > threshold && i < n)
	{
		printf("%d(%d) ", values[i], indexes[i]);
		i++;
	}
	printf("\n");
	i =0;


}




int main()
{
	uint_least16_t i;
//	uint_least16_t n;
	int_least32_t threshold = 20; //when not using global variables
	static int_least32_t values[4000]; //when not using global variables
	static uint_least16_t indexes[4000]; //when not using global variables
	static uint_least16_t indexes_of_even_values[4000]; //when not using global variables
	static int_least32_t even_values[4000]; //when not using global variables
	static int k;//when not using global variables
	static uint_least16_t n; //when not using global variables


	printf("Number of elements: ");
	fflush(stdout); // added because of eclipse console
	scanf("%hd", &n);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%d. element: ", i+1);
		fflush(stdout); // added because of eclipse console
		scanf("%d", &values[i]);
		indexes[i] = i;

	}

	sort(values, indexes, n);

	print(values, indexes, n, threshold);
	printf("Even numbers up to the threshold: ");

	k = even_numbers(values, indexes, even_values, indexes_of_even_values, n, threshold);

	for(i = 0 ; i < k; i++  )
	{
		printf("%d. even element: %d \n",i+1, even_values[i]);
	}

	return 0;
}
