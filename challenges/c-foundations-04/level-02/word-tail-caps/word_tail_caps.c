#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		write(1, "wrong number of arguments\n", 26);
		return 0;
	}

	int i = 0;
	int j = 1;

	while (j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			if (av[j][i] >= 'A' && av[j][i] <= 'Z')
				av[j][i] += 32;
			
			if ((av[j][i] >= 'a' && av[j][i] <= 'z') && (av[j][i + 1] == ' ' || av[j][i + 1] == '\0' || (!(av[j][i + 1] >= 'a' && av[j][i + 1] <= 'z'))))
				av[j][i] -= 32;
			i++;
		}

		i = 0;
		while (av[j][i])
			write(1, &av[j][i++], 1);
		write (1, "\n", 1);

		j++;
	}
	return (0);
}
