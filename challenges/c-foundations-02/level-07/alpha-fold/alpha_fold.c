#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "wrong number of arguments", 25);
	else
	{
		while (*argv[1])
		{
			char c = *argv[1];
			int position = 0;
			if (c >= 'a' && c <= 'm')
			{
				position = c - 'a';
				c = 'z' - position;
				write(1, &c, 1);
			}
			else if (c >= 'n' && c <= 'z')
			{
				position = 'z' - c;
				c = 'a' + position;
				write(1, &c, 1);
			}
			else
				write(1, &c, 1);

			argv[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
