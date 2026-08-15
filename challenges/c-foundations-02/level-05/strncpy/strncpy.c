#include <stddef.h>

char	*strncpy(char *dst, const char *src, size_t n)
{
	size_t i = 0;
	int len = 0;

	if (n == 0)
		return (dst);

	while (src[len])
		len++;
		
	char *d = dst;
	while (*src && i < n)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	while (i < n)
	{
		*dst = '\0';
		dst++;
		i++;
	}
	return (d);
}
