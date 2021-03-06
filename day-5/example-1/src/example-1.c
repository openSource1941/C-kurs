#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

static const int_least32_t threshold1 = 20;
static const int_least32_t threshold2 = 30;
static const int_least32_t threshold3 = 40;


typedef struct _s
{
	int_least32_t value;
	int_least16_t index;
} val_ind_struct_t;

static val_ind_struct_t struct_array[4000];



static void bubble_sort(val_ind_struct_t* str_array, int_least16_t n)
{
	int_least16_t i;
	int_least16_t j;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (str_array[i].value < str_array[j].value)
			{
				val_ind_struct_t tmp;

				tmp = str_array[i];
				str_array[i] = str_array[j];
				str_array[j] = tmp;
			}
		}
	}
}


static int compare(const void* x, const void* y)
{
	ptrdiff_t res = *(int*)x - *(int*)y;
	return res;
}


static void quick_sort(val_ind_struct_t* str_array, int_least16_t n)
{
	qsort(str_array,n,sizeof(str_array[0].value), compare );
	// sort using qsort standard function
}

static void print(const val_ind_struct_t* str_array, int_least16_t n, int_fast8_t tr_index)
{
	int_least16_t i = 0;
	int_least32_t threshold;
	printf("Up to the %d. threshold: ", tr_index);


	if(tr_index == 1)
		threshold = threshold1;
	else if (tr_index == 2)
		threshold =threshold2;
	else if (tr_index == 3)
		threshold = threshold3;
	else
		printf("Start the program again and choose between offered options!!!");
/*	switch (tr_index)
	{
	case 1:
		threshold = treshold1;
		break;
	case 2:
		threshold = treshold2;
		break;
	case 3:
		threshold = treshold3;
		break;
	}*/



	while (str_array[i].value > threshold && i < n)
	{
		printf("%d(%d) ", str_array[i].value, str_array[i].index);
		i++;
	}
	printf("\n");
}


int main()
{
	int_least16_t i;
	int n;

	int threshold_index;
	int sort_index;
	printf("Number of elements: ");
	fflush(stdout); // added because of eclipse console
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("%d. element: ", i);
		fflush(stdout); // added because of eclipse console
		scanf("%" SCNd32, &(struct_array[i].value));
		struct_array[i].index = i;
		printf("\n");
	}

	printf("Threshold you want to use (1, 2, or 3): ");
	fflush(stdout); // added because of eclipse console
	scanf("%d", &threshold_index);

	printf("\n");
	printf("Sorting algorithm you want to use (1- bubble, 2- quick): ");
	fflush(stdout); // added because of eclipse console
	scanf("%d", &sort_index);
	printf("\n");
	sort_index =1 ;


	if(sort_index == 1)
		bubble_sort(struct_array, n);
	else if (sort_index == 1)
		quick_sort(struct_array, n);
	else
		printf("Start the program again and choose between offered options!!!");
/*	switch (sort_index)
	{
	case 1:
		bubble_sort(struct_array, n);
		break;
	case 2:
		quick_sort(struct_array, n);
		break;
	}*/

	printf("All elements:");
	for(int i = 0; i<n; i++)
	{
		printf("\n%d(%d) ", struct_array[i].value, struct_array[i].index);
	}

	printf("\n");

	print(struct_array, n, threshold_index);
	return 0;
}
