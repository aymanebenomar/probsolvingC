#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "wrong number of arguments", 25);
	else
	{
		char c;
		int rep;
		int i = 0;
		while (argv[1][i])
		{
			rep = 0;
			c = argv[1][i];
			if (c >= 'a' && c <= 'z')
				rep = c - 'a';
			else if (c >= 'A' && c <= 'Z')
				rep = c - 'A';
			else
				write(1, &c, 1);
				
			while (rep >= 1)
			{
				write(1, &c, 1);
				rep--;
			}
			i++;
		}
	}

	write(1, "\n", 1);
	return (0);
}