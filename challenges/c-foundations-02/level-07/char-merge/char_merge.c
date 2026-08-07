#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
		write(1, "wrong number of arguments", 25);
	else
	{
		char seen[256] = {};
		while (*argv[2])
		{
			if(seen[(unsigned char)*argv[2]] == 0)
			{
				write(1, argv[2], 1);
				seen[(unsigned char)*argv[2]] = 1;
			}
			argv[2]++;
		}
		while (*argv[1])
		{
			if (seen[(unsigned char)*argv[1]] == 0)
			{
				write(1, argv[1], 1);
				seen[(unsigned char)*argv[1]] = 1;
			}
			argv[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
