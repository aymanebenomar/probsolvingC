#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	int params = argc - 1;

	if (argc == 1)
		return 0;
	while (params >= 1)
	{
		i = 0;
		while (argv[params][i])
			write(1, &argv[params][i++], 1);
		write(1, "\n", 1);
		params--;
	}
	return (0);
}
