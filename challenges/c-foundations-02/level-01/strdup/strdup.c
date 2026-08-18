#include <stdlib.h>

char *strdup(const char *src)
{
	int i = 0;
	while (src[i])
		i++;

	char *arr = malloc(sizeof(char) * (i + 1));
	
	if (!arr)
		return (NULL);

	i = 0;
	while (src[i])
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
