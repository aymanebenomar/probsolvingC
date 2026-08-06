#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return 0;
	}
	else
	{
		int count;
		int i = 0;
		char c;
		while (argv[1][i])
		{
			count = 0;
			c = argv[1][i];
			if (c >= 'a' && c <= 'z')
				count = c - 'a';
			else if (c >= 'A' && c <= 'Z')
				count = c - 'A';
			if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
				write(1, &c, 1);

			if (count != 0)
			{
				while (count > 0)
				{
					write(1, &c, 1);
					count--;
				}
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
