#include <stddef.h>

void	*memset(void *s, int c, size_t n)
{
	char *ss = s;

	if (n == 0)
		return (s);
	
	size_t i = 0;

	while (i < n)
		ss[i++] = (unsigned char)c;
	
	return (s);
}