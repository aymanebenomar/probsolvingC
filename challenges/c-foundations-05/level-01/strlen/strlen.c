#include <stddef.h>

size_t	strlen(const char *s)
{
	const char *first = s;
	while (*s)
		s++;
	return (s - first);
}
