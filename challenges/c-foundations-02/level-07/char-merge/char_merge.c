#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write (1, "wrong number of arguments\n", 26);
		return 0;
	}

	char s[256] = {};
	int i = 0;
	int j = 0;

	while (av[2][i])
	{
		if (s[(unsigned char)av[2][i]] == 0)
		{
			write(1, &av[2][i], 1);
			s[(unsigned char)av[2][i]] = 1;
		}
		i++;
	}

	while (av[1][j])
	{
		if (s[(unsigned char)av[1][j]] == 0)
		{
			write(1, &av[1][j], 1);
			s[(unsigned char)av[1][j]] = 1;
		}
		j++;
	}

	write(1, "\n", 1);
	return (0);
}
