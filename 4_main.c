#include <stdio.h>
#include <stdlib.h>
#include "4_head.h"

int main(void)
{
	double x, current;
	double *arr;
	int len = 0, capacity = 2;
	FILE *f;

	printf("enter x: ");
	if (scanf("%lf", &x) != 1)
	{
		printf("enter error\n");
		return -1;
	}

	f = fopen("4_data.txt", "r");
	if (f == NULL)
	{
		printf("file error\n");
		return -2;
	}

	arr = (double *)malloc(capacity * sizeof(double));

	while (fscanf(f, "%lf", &current) == 1)
	{
		++len;
		if (len > capacity)
		{
			capacity *= 2;
			arr = (double *)realloc(arr, capacity * sizeof(double));
		}
		arr[len - 1] = current;
	}
	fclose(f);
	printf ("array before process\n");
	print_arr(arr, len);
	printf ("array after process\n");

	process_array(arr, len, x);
	print_arr(arr, len);

	free(arr);
	return 0;
}