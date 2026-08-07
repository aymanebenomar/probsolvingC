#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "wrong number of arguments", 25);
	else
	{
		while (*argv[1] && ((*argv[1] >= 9 && *argv[1] <= 13) || *argv[1] == ' '))
			argv[1]++;
		while (*argv[1] && !((*argv[1] >= 9 && *argv[1] <= 13) || *argv[1] == ' '))
			write(1, argv[1]++, 1);
	}
	write(1, "\n", 1);
	return (0);
}
