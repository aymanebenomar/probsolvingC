#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return 0;
	}

	int last = argc - 1;
	while (*argv[last])
	{
		write(1, argv[last], 1);
		argv[last]++;
	}
	
	write(1, "\n", 1);
	return (0);
}
