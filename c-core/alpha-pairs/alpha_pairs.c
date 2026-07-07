#include <unistd.h>

int	main()
{
	char alpha = 'a';
	char secalpha;
	while (alpha <= 'z')
	{
		if (alpha % 2 != 0)
		{
			write(1, &alpha, 1);
			write(1, &alpha, 1);
		}
		else {
			secalpha = alpha - 32;
			write(1, &secalpha, 1);
			write(1, &secalpha, 1);
		}
		alpha++;
	}
	write(1, "\n", 1);
	return (0);
}
