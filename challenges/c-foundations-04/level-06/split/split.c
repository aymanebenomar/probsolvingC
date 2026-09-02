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
int count(char *s, char *charset)
{
	int i = 0;
	int res = 0;
	while (s[i])
	{
		while (s[i] && check(s[i], charset))
			i++;
		if (s[i] && !check(s[i], charset))
		{
			res++;
			while (s[i] && !check(s[i], charset))
				i++;
		}
	}
	return (res);
}

char **split(char *str, char *charset)
{
	int 	i;
	int 	w;
	int 	j;
	char 	**arr;

	arr = malloc ((count(str, charset) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	
	i = 0;
	w = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && check(str[i], charset))
			i++;
		if (str[i] && !check(str[i], charset))
		{
			j = 0;
			while (str[i] && !check(str[i], charset))
			{
				j++;
				i++;
			}
			arr[w] = malloc ((j + 1) * sizeof(char));
			if (!arr[w])
				return (NULL);
			w++;
		}
	}

	i = 0;
	w = 0;
	j = 0;
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

// #include <stdio.h>
// int main ()
// {
// 	char **s = split("cargo build --release", " -");
// 	int i = 0;
// 	while (s[i])
// 		printf("%s\n", s[i++]);
// 	return 0;
// }