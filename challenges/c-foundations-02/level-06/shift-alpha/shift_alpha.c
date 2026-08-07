#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "wrong number of arguments", 25);
	else
	{
		char c;
		while(*argv[1])
		{
			c = *argv[1];
			if (c == 'z')
				c = 'a';
			else if (c == 'Z')
				c = 'A';
			else if ((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z'))
				c++;
			write(1, &c, 1);
			argv[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
