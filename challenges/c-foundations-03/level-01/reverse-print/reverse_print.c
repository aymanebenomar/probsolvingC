#include <unistd.h>

int	main(int argc, char **argv)
{
	int last = 0;
	if (argc == 2)
	{
		while (argv[1][last])
			last++;
		last--;
		while (last >= 0)
		{
			write(1, &argv[1][last], 1);
			last--;
		}

	}
	else
		write(1, "wrong number of arguments", 25);

	write(1, "\n", 1);
	return (0);
}