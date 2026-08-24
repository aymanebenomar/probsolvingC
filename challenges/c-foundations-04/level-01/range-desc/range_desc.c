#include <stdlib.h>

int *range_desc(int min, int max)
{
	int i = 0;
	int rng;
	int *res;

	rng = max - min;
	res = malloc((rng + 1) * sizeof(int));
	if (!res)
		return (NULL);
	while (i <= rng)
	{
		res[i++] = max;
		max--;
	}
	return (res);
}

// #include <stdio.h>
// int main ()
// {
// 	int *arr = range_desc(1, 4);
// 	int i = 0;
// 	while (i <= 3)
// 		printf("%d", arr[i++]);
// 	return 0;
// }