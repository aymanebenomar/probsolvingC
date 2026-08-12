#include <unistd.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	char alpha = 'a';
	char c;
	int count;

	while (alpha <= 'z')
	{
		count = 2;
		c = alpha;
		if (alpha % 2 == 0)
			c -= 32;
		while (count > 0)
		{
			write(1, &c, 1);
			count--;
		}
		alpha++;
	}
	write(1, "\n", 1);
	return (0);
}