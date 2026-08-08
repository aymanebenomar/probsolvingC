#include <stddef.h>

static void	swap_bytes(unsigned char *a, unsigned char *b, size_t size)
{
	unsigned char	tmp;
	size_t			i;

	i = 0;
	while (i < size)
	{
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
		i++;
	}
}

void	qsort(void *base, size_t nmemb, size_t size,
		int (*cmp)(const void *, const void *))
{
	unsigned char	*b;
	size_t			i;
	size_t			j;

	if (nmemb < 2 || size == 0)
		return;

	b = (unsigned char *)base;
	i = 0;
	while (i < nmemb - 1)
	{
		j = 0;
		while (j < nmemb - 1 - i)
		{
			if (cmp(b + j * size, b + (j + 1) * size) > 0)
				swap_bytes(b + j * size, b + (j + 1) * size, size);
			j++;
		}
		i++;
	}
}