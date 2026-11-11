#include <stdio.h>
#include <stdlib.h>
#include "4_head.h"

int main(void)
{
	double x, current;
	double *arr;
	int len = 0, capacity = 2;
	FILE *f;

	printf("введи x: ");
	if (scanf("%lf", &x) != 1)
	{
		printf("неверный ввод\n");
		return -1;
	}

	f = fopen("4_data.txt", "r");
	if (f == NULL)
	{
		printf("ошибка файла\n");
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

	process_array(arr, len, x);
	print_arr(arr, len);

	free(arr);
	return 0;
}