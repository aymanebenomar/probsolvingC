#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	int len = 0;
	char temp;
	if (argc == 2)
	{
		while (argv[1][len])
			len++;
		len--;
		while (len > i)
		{
			temp = argv[1][i];
			argv[1][i] = argv[1][len];
			argv[1][len] = temp;
			len--;
			i++;
		}

		i = 0;
		while (argv[1][i])
			write(1, &argv[1][i++], 1);
			
		write(1, "\n", 1);
	}
	else 
		write(1, "wrong number of arguments\n", 26);
	return (0);
}
