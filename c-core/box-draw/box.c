#include <stdlib.h>
#include <unistd.h>

// argv[1] is the width, argv[2] the height. Draw the frame of that rectangle:
// '+' corners, '-' on top and bottom, '|' on the sides, spaces inside.
int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "wrong number of arguments\n", 26);
		return 0;
	}
	else
	{
		int width = atoi(argv[1]);
		int height = atoi(argv[2]);
		
		if (width <= 0 || height <= 0)
			return 0;

		char plus = '+';
		char minus = '-';
		int nn = height;
		while (height > 0)
		{
			int n = width;
			if(height == nn || height == 1)
			{
				while (n > 0)
				{
					if (n == width)
						write(1, &plus, 1);
					else if (n == 1)
						write(1, &plus, 1);
					else
						write(1, &minus, 1);
					n--;
				}
				write(1, "\n", 1);
			}
			else 
			{
				while (n > 0)
				{
					if (n == 1)
						write(1, "|", 1);
					else if (n == width)
						write(1, "|", 1);
					else
						write(1, " ", 1);
					n--;
				}
				write(1,"\n", 1);
			}
			height--;
		}
	}
	return (0);
}
