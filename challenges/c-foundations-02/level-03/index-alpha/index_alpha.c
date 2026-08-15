#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "wrong number of arguments", 25);
	else
	{
		int count;
		char c;
		while (*argv[1])
		{
			c = *argv[1];
			count = 0;
			if (c >= 'a' && c <= 'z')
			{
				count = (c - 'a');
				while (count > 0)
				{
					write(1, &c, 1);
					count--;
				}
			}
			else if (c >= 'A' && c <= 'Z')
			{
				count = (c - 'A');
				while (count > 0)
				{
					write(1, &c, 1);
					count--;
				}
			}
			else
				write(1, &c, 1);
			argv[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
