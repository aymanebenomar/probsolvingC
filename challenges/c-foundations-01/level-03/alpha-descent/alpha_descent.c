#include <unistd.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	char alpha = 'z';
	int i = 13;
	char uper[2];
	while(alpha >= 'a')
	{
		if (i % 2 != 0)
		{
			uper[0] = alpha - 32;
			alpha--;
			uper[1] = alpha - 32;
			alpha--;
			write (1, &uper[0], 1);
			write (1, &uper[1], 1); 
			i--;
		}
		else {
			write(1, &alpha, 1);
			alpha--;
			write(1, &alpha, 1);
			alpha--;
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
