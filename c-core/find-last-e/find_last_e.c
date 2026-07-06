#include <unistd.h>

int	main(int argc, char **argv)
{
	if(argc != 2)
	{
		write(1, "e\n", 2);
	}

	int i = 0;
	int last;
	if (argc == 2)
	{
		while(argv[1][i])
		{
			i++;
		}
		last = i - 1;
		i = 0;
		while(last >= 0)
		{
			if (argv[1][last] == 'e')
			{
				write(1, "e\n", 2);
				return 0;
			}
			last--;
		}
		write(1, "\n", 1);
	}
	return (0);
}
