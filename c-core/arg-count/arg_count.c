#include <unistd.h>

int	main(int argc, char **argv)
{
	(void)argv;
	int n;
	if (argc >= 2)
	{
		n = (argc - 1) + 48;
		write(1, &n, 1);
		write(1, "\n", 1);
	}
	else {
		write(1, "0\n", 2);
	}
	return (0);
}
