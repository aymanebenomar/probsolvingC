#include <stddef.h>

// Return 1 when a[0..n - 1] never decreases, 0 at the first drop.
// Equal neighbours keep the answer 1. n of 0 or 1 is sorted by convention.
int	is_sorted(const int *a, size_t n)
{
	int i = 0;
	int j;

	if (n == 0 || n == 1)
		return (1);
	
	while (i < (int)n)
	{
		j = i + 1;
		if (j < (int)n && a[i] > a[j])
			return (0);
		i++;
	}
	if (i == (int)n)
		return (1);
	return (0);
}
