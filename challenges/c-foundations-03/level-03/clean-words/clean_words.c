#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write (1, "wrong number of arguments\n", 26);
		return 0;
	}

	int i = 0;
	while (av[1][i])
	{
		while (av[1][i] && ((av[1][i] >= 9 && av[1][i] <= 13) || av[1][i] == ' '))
			i++;
		while (av[1][i] && !((av[1][i] >= 9 && av[1][i] <= 13) || av[1][i] == ' '))
			write(1, &av[1][i++], 1);
		while (av[1][i] && ((av[1][i] >= 9 && av[1][i] <= 13) || av[1][i] == ' '))
			i++;
		if (av[1][i])
			write (1, " ", 1);
	}
	write (1, "\n", 1);
	return (0);
}
