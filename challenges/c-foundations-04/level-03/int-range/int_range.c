#include <stdlib.h>

int *int_range(int from, int to)
{
	int i = 0;
	int *arr;

	if (from <= to)
	{
		arr = malloc((to - from + 1) * sizeof(int));
		if (!arr)
			return (NULL);
		while (from <= to)
		{
			arr[i++] = from;
			from++;
		}
	}
	else if (from >= to)
	{
		arr = malloc((from - to + 1) * sizeof(int));
		if (!arr)
			return (NULL);
		while (from >= to)
		{
			arr[i++] = from;
			from--;
		}
	}
	return (arr);
}
