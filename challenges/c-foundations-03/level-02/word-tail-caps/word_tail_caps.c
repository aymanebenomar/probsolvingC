#include <unistd.h>

int	is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '\0')
		return (1);
	return (0);
}

int	has_letter_after(char *str, int i)
{
	i++;
	while (!is_separator(str[i]))
	{
		if (is_alpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	print_tail_caps(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (is_alpha(c))
		{
			if (has_letter_after(str, i))
			{
				if (c >= 'A' && c <= 'Z')
					c += 32;
			}
			else
			{
				if (c >= 'a' && c <= 'z')
					c -= 32;
			}
		}
		write(1, &c, 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		print_tail_caps(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}