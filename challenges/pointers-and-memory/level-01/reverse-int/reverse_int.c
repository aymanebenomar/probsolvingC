#include <stddef.h>

void	reverse_int(int *a, size_t n)
{
	size_t i = 0;
	size_t last = n - 1;
	int temp;

	if (n == 0)
		return;

	while (i < last)
	{
		temp = a[last];
		a[last] = a[i];
		a[i] = temp;
		i++;
		last--;
	}
}
