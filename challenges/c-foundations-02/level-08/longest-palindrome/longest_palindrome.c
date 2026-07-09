#include <unistd.h>

int	is_pal(char *str, int start, int end)
{
	while (start < end)
	{
		if (str[start] != str[end])
			return (0);
		start++;
		end--;
	}
	return (1);
}

void	print_substr(char *str, int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write(1, &str[start + i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	best_start;
	int	best_len;
	int	len;

	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	i = 0;
	best_start = 0;
	best_len = 0;
	while (argv[1][i])
	{
		j = i;
		while (argv[1][j])
		{
			len = j - i + 1;
			if (len > best_len && is_pal(argv[1], i, j))
			{
				best_start = i;
				best_len = len;
			}
			j++;
		}
		i++;
	}
	print_substr(argv[1], best_start, best_len);
	return (0);
}