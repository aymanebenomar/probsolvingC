#include <stddef.h>

static size_t	my_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static int	my_strcmp(const char *a, const char *b)
{
	size_t	i;

	i = 0;
	while (a[i] != '\0' && a[i] == b[i])
		i++;
	return ((unsigned char)a[i] - (unsigned char)b[i]);
}

static int	is_after(char *const *arr, size_t i, size_t j)
{
	size_t	len_i;
	size_t	len_j;
	int		cmp;

	len_i = my_strlen(arr[i]);
	len_j = my_strlen(arr[j]);
	if (len_i != len_j)
		return (len_i > len_j);
	cmp = my_strcmp(arr[i], arr[j]);
	if (cmp != 0)
		return (cmp > 0);
	return (i > j);
}

void	argsort_len(char *const *arr, size_t n, size_t *out)
{
	size_t	i;
	size_t	j;
	size_t	key;

	if (n == 0)
		return ;
	i = 0;
	while (i < n)
	{
		out[i] = i;
		i++;
	}
	i = 1;
	while (i < n)
	{
		key = out[i];
		j = i;
		while (j > 0 && is_after(arr, out[j - 1], key))
		{
			out[j] = out[j - 1];
			j--;
		}
		out[j] = key;
		i++;
	}
}