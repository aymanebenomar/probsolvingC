#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "wrong number of arguments\n", 26);
		return 0;
	}

	int i = 0;
	int j = 0;
	while (argv[2][i])
	{
		if (argv[2][i] == argv[1][j])
			j++;
		if (argv[1][j] == '\0')
		{
			write(1, "yes\n", 4);
			return 0;
		}
		i++;
	}
	write(1, "no\n", 3);
	return (0);
}
