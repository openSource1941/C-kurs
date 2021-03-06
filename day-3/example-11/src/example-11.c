
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


static int THRESHOLD=20;
int_least32_t values[40000];
int_least16_t indexes[40000];

void sort(int_least32_t* values, int_least16_t* indexes, const int_least16_t n)
{
	int_least16_t i;
	int_least16_t j;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (values[i] < values[j])
			{
				int_least32_t tmp;
				int_least16_t tmp1;

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


void print(int_least32_t* values, int_least16_t* indexes,const int_least16_t n)
{
	int_least16_t i = 0;
	printf("Up to the first threshold: ");
	while (values[i] > THRESHOLD && i < n)
	{
		printf("%d(%d) ", values[i], indexes[i]);
		i++;
	}
	printf("\n");
}





int main()
{
	int_least16_t i;
	int_least16_t n;

	printf("Number of elements: ");
	fflush(stdout); // added because of eclipse console

	scanf("%hd", &n);
	printf("\n");

	for (i = 0; i < n; i++)
	{
		printf("%d. element: ", i);
		fflush(stdout); // added because of eclipse console
		scanf("%d", &values[i]);
		indexes[i] = i;
	}

	sort(values, indexes, n);

	print(values, indexes, n);

	return 0;
}
