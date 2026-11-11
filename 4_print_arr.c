#include <stdio.h>
#include "4_head.h"

void print_arr(double *arr, int len)
{
	int i;

	printf("\nArray:\n");
	for (i = 0; i < len; i++) printf("arr[%d] = %.1lf\n", i, arr[i]);
	printf("\n");
}