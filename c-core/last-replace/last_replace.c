#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	if (argc == 4)
	{
		if (argv[2][0] == '\0' || argv[2][1] != '\0')
		{
			write(1, "\n", 1);
			return 0;
		}
		else if (argv[3][0] == '\0' || argv[3][1] != '\0')
		{
			write(1, "\n", 1);
			return 0;	
		}
		while (argv[1][i])
			i++;
		while (i > 0)
		{
			if (argv[1][i] == argv[2][0])
			{
				argv[1][i] = argv[3][0];
				break;
			}
			i--;
		}
		while (i > 0)
			i--;
		while (argv[1][i])
		{
			write(1, &argv[1][i], 1);
			i++;
		}

	}
	else
		write(1, "wrong number of arguments", 25);
	write(1, "\n", 1);
	return 0;
}
