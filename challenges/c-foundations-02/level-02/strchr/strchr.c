#include <stddef.h>

char	*strchr(const char *s, int c)
{
	const char *first = s;
	int len = 0;
	while (*s)
		s++;
	len = s - first;
	s = first;
	while (len >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		len--;
	}
	return (NULL);
}
