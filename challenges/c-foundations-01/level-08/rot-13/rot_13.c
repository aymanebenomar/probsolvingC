#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	char	change;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			if ((argv[1][i] <= 'm' && argv[1][i] >= 'a') || (argv[1][i] <= 'M' && argv[1][i] >= 'A'))
			{
				change = argv[1][i] + 13;
				write (1, &change, 1);
			}
			else if ((argv[1][i] >= 'n' && argv[1][i] <= 'z') ||(argv[1][i] >= 'N' && argv[1][i] <= 'Z'))
			{
				change = argv[1][i] - 13;
				write(1, &change, 1);
			}
			else
			{
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	else 
	{
		write(1, "wrong number of arguments", 25);
	}
	write(1, "\n", 1);
	return (0);
}
