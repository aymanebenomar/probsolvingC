#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	if (argc == 2)
	{
		while(argv[1][i])
			i++;
		i -= 1;
		while (i >= 0)
			write(1, &argv[1][i--], 1);	
	}
	else
		write(1, "wrong number of arguments", 25);
	write(1, "\n", 1);
	return (0);
}
