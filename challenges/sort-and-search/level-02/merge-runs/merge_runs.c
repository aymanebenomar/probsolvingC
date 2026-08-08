#include <stddef.h>
#include <stdio.h>

// out receives the ln + rn values of left and right merged in ascending order.
// Both runs arrive sorted; when the two fronts are equal, left goes first.
void	merge_runs(const int *left, size_t ln, const int *right, size_t rn, int *out)
{
	int i = 0;
	int j = 0;
	int fullsize = (int)ln + (int)rn;

	while (i < (int)ln)
	{
		out[i] = left[i];
		i++;
	}
	while (j < (int)rn)
	{
		out[i] = right[j];
		i++;
		j++;
	}

	i = 0;
	while (i < fullsize)
	{
		j = i + 1;
		while(j < fullsize)
		{
			int temp;
			if (out[i] > out[j])
			{
				temp = out[i];
				out[i] = out[j];
				out[j] = temp;
			}
			j++;
		}
		i++;
	}
}

/* int main()
{
	int out[20];
	size_t n = 3;
	const int left[] = {1, 3, 5};
	const int right[] = {2, 4, 6};
	merge_runs(left, n, right,n ,out);

	int i = 0;
	while (i < 6)
	{
		printf("%d", out[i++]);
	}
	return 0;
} */