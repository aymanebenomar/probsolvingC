#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	char c;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			c = argv[1][i];
			if ((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z'))
				c = argv[1][i] + 1;
			else if (argv[1][i] == 'z')
				c = 'a';
			else if (argv[1][i] == 'Z')
				c = 'A';
			write(1, &c, 1);
			i++;
		}
		write(1, "\n", 1);
	}
	else {
		write(1, "wrong number of arguments\n", 26);
	}
	return (0);
}
