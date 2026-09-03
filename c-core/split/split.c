#include <stdlib.h>

int check(char c, char *charset)
{
	int i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int countw(char *s, char *charset)
{
	int i = 0;
	int count = 0;

	while (s[i])
	{
		while (s[i] && check(s[i], charset))
			i++;
		if (s[i] && !check(s[i], charset))
		{
			count++;
			while (s[i] && !check(s[i], charset))
				i++;
		}
	}
	return (count);
}

char **split(char *str, char *charset)
{
	int i = 0;
	int j = 0;
	int w = 0;
	char **arr;

	arr = malloc((countw(str, charset) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	
	while (str[i])
	{
		while (str[i] && check(str[i], charset))
			i++;
		if (str[i] && !check(str[i], charset))
		{
			j = 0;
			while (str[i] && !check(str[i], charset))
			{
				i++;
				j++;
			}
			arr[w] = malloc ((j + 1) * sizeof(char));
			if (!arr[w])
				return (NULL);
			w++;
		}
	}

	i = 0;
	j = 0;
	w = 0;
	while (str[i])
	{
		while (str[i] && check(str[i], charset))
			i++;
		if (str[i] && !check(str[i], charset))
		{
			j = 0;
			while (str[i] && !check(str[i], charset))
			{
				arr[w][j++] = str[i];
				i++;
			}
			arr[w][j] = '\0';
			w++;
		}
	}

	arr[w] = NULL;
	return (arr);
}