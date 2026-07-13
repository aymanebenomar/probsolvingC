#include <stddef.h>

size_t	strcspn(const char *s, const char *reject)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == reject[0])
			return (i);
		i++;
	}
	return (i);
}
