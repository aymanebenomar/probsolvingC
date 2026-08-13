#include <unistd.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char alpha = 'a';
	char c;
	int times;

	while (alpha <= 'z')
	{
		times = 2;
		c = alpha;
		if (c % 2 == 0)
			c -= 32;
		while (times > 0)
		{
			write(1, &c, 1);
			times--;
		}
		alpha++;
	}
	write(1, "\n", 1);
	return (0);
}
