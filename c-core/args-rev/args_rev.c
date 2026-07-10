#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	int arg = argc - 1;
	while (arg > 0)
	{
		i = 0;
		while (argv[arg][i])
		{
			write(1, &argv[arg][i], 1);
			i++;
		}
		write(1, "\n", 1);
		arg--;
	}
	return (0);
}
