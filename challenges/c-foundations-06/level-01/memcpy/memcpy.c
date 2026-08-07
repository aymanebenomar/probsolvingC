#include <stddef.h>

void	*memcpy(void *dst, const void *src, size_t n)
{
	char *d = (char *)dst;
	const char *s = (const char *)src;

	char *first = d;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (first);
}
