#include <unistd.h>

int	main(int ac, char **av)
{
	int i = 0;
	int alpha = 0;

	if (ac != 2)
	{
		write (1, "wrong number of arguments\n", 26);
		return 0;
	}

	while (av[1][i])
	{
		alpha = 0;

		if (av[1][i] >= 'a' && av[1][i] <= 'z')
			alpha = av[1][i] - 'a';
		else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			alpha = av[1][i] - 'A';
		else
			alpha = 1;

		if (alpha > 0 && !(av[1][i] == 'a' && av[1][i] == 'A'))
		{
			while (alpha > 0)
			{
				write (1, &av[1][i], 1);
				alpha--;
			}
		}
		i++;
	}
	write (1, "\n", 1);
	return (0);
}
