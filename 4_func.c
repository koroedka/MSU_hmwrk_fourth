#include <stdlib.h>
#include "4_head.h"

void process_array(double *arr, int len, double x)
{
	int *otrezki;
	int count = 0;
	int i, k, s, j, start, end;
	double left, right, val;

	otrezki = (int *)malloc(2 * len * sizeof(int));
	if (otrezki == NULL) return;

	for (i = 0; i < len; i++)
	{
		if (arr[i] == x)
		{
			start = i;
			k = i;

			while (k < len && arr[k] == x) k++;
			end = k - 1;

			otrezki[2 * count]     = start;
			otrezki[2 * count + 1] = end;
			count++;

			i = end;
		}
	}

	for (s = 0; s < count; s++)
	{
		start = otrezki[2 * s];
		end   = otrezki[2 * s + 1];

		if (start > 0) left = arr[start - 1];
		else left = 0.0;

		if (end < len - 1) right = arr[end + 1];
		else right = 0.0;

		val = (left + right) / 2.0;

		for (j = start; j <= end; j++) arr[j] = val;
	}

	free(otrezki);
}