#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc > 1)
		return 0;
		
	(void)argc;
	(void)argv;

	char alpha = 'a';
	while (alpha <= 'z')
	{
		int count = 2;
		char c = alpha;
		if (c % 2 == 0)
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
