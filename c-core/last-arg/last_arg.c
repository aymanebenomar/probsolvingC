#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	if (argc < 2)
	{
		write(1, "wrong number of arguments\n", 26);
	}
	if (argc >= 2)
	{
		while (argv[argc - 1][i] != '\0' && argv[argc - 1][i] != ' ')
		{
			write(1, &argv[argc - 1][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}