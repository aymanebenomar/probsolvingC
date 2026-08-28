#include <stddef.h>

char	*strchr(const char *s, int c)
{
	int i = 0;
	int len = 0;
	while (s[len])
		len++;
	
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}