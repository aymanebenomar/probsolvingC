#include <stddef.h>

// Flip the order of the first n elements of a, in place.
// Nothing past that prefix moves, and n == 0 changes nothing.
void	reverse_int(int *a, size_t n)
{
	if (n == 0)
		return;

	size_t i = 0;
	size_t last = n - 1;
	int temp;

	while (i < last)
	{
		temp = a[i];
		a[i] = a[last];
		a[last] = temp;
		i++;
		last--;
	}
}
