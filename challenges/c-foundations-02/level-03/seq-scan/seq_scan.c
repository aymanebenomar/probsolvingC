#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write (1, "wrong number of arguments\n", 26);
		return 0;
	}

	char buff[300];
	int i = 0;
	int j;

	while (argv[1][i])
	{
		char c = argv[1][i];
		if (c >= 'A' && c <= 'Z')
			c += 32;
		buff[i] = c;
		i++;
	}
	buff[i] = '\0';

	i = 0;
	while (argv[2][i])
	{
		if (argv[2][i] >= 'A' && argv[2][i] <= 'Z')
			argv[2][i] += 32;
		i++;
	}

	j = 0;
	i = 0;
	while (argv[2][i])
	{
		if (argv[2][i] == buff[j])
			j++;
		i++;
	}

	if (buff[j] == '\0')
	{
		i = 0;
		while (argv[1][i])
			write (1, &argv[1][i++], 1);
		write(1, "\n", 1);
		return 0;
	}
	write (1, "\n", 1);
	return (0);
}
