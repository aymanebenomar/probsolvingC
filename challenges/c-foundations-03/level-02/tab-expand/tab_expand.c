#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	col;
	int	spcrep;

	if (ac != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	i = 0;
	col = 0;
	while (av[1][i])
	{
		if (av[1][i] == ' ')
		{
			spcrep = 8 - (col % 8);
			while (spcrep > 0)
			{
				write(1, " ", 1);
				spcrep--;
				col++;
			}
		}
		else
		{
			write(1, &av[1][i], 1);
			col++;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}