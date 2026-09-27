#include <stddef.h>

void	*gm_memset(void *s, int c, size_t n)
{
	size_t i = 0;
	char *ss = (char *)s;
	while (i < n)
	{
		*ss = c;
		ss++;
		i++;
	}
	return (s);
}
