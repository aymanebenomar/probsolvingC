#include <stddef.h>

char	*gm_strncat(char *dst, const char *src, size_t n)
{
	size_t dlen = 0;
	size_t i = 0;

	while (dst[dlen])
		dlen++;
	
	while (src[i] && i < n)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dst);
}
