#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int result, a, b;
	if (argc == 4)
	{
	 	a = atoi(argv[1]);
		b = atoi(argv[3]);

		if (argv[2][0] == '*')
			result = a * b;
		else if (argv[2][0] == '+')
			result = a + b;
		else if (argv[2][0] == '-')
			result = a - b;
		else if (argv[2][0] == '/')
			result = a / b;
		else if (argv[2][0] == '%')
			result = a % b;
		printf("%d", result);
		printf("\n");
	}
	else {
		write(1, "wrong number of arguments\n", 26);
	}
	return (0);
}
