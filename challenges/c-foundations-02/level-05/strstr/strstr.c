#include <stddef.h>

char	*strstr(const char *haystack, const char *needle)
{
	if (needle[0] == '\0')
		return ((char *)haystack);

	int i = 0;
	int j = 0;
	while (haystack[i])
	{
		while (needle[j] && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}