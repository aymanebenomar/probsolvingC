#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write (1, "wrong number of arguments\n", 26);
		return 0;
	}

	int i = 0;
	int j = 0;
	char s[256] = {};

	while (av[1][i])
	{
		if (s[(unsigned char)av[1][i]] == 0)
			s[(unsigned char)av[1][i]] = 1;
		i++;
	}

	while (av[2][j])
	{
		if (s[(unsigned char)av[2][j]] == 1)
		{
			write (1, &av[2][j], 1);
			s[(unsigned char)av[2][j]] = 0;
		}
		j++;
	}

	write(1, "\n", 1);
	return (0);
}
