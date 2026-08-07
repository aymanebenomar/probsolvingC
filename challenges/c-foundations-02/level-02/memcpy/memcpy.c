#include <stddef.h>

void	*memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d = (unsigned char *)dst;
	const unsigned char *s = (const unsigned char *)src;

	unsigned char *first = d;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (first);
}
