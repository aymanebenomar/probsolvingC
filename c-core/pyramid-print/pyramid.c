#include <stdlib.h>
#include <unistd.h>

// argv[1] is the height. Print a centered pyramid of '#', one row per line.
// A wrong argument count prints "wrong number of arguments" and a newline.
int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return 0;
	}

	int height = atoi(av[1]);

	if (height <= 0)
		return 0;

	int space = height;
	int row = 1;
	int hash = 1;
	int s = 0;
	int h = 0;

	while (row <= height)
	{
		s = space;
		h = hash;
		while (s > 1)
		{
			write (1, " ", 1);
			s--;
		}
		while (h > 0)
		{
			write(1, "#", 1);
			h--;
		}
		write (1, "\n", 1);
		space--;
		hash += 2;
		row++;
	}
	return (0);
}
