#include <stdio.h>
#include <stdlib.h>

// Read the value. Print it if it fits in a signed 16-bit int (-32768 to 32767),
// otherwise print OVERFLOW. Do not let it silently wrap.
int	main(int argc, char **argv)
{
	long	value;

	if (argc != 2)
	{
		printf("wrong number of arguments\n");
		return (1);
	}
	value = atol(argv[1]);
	// TODO: print value if it fits in a signed 16-bit int, else print OVERFLOW
	if (value >= -32768 && value <= 32767)
	{
		printf("%d", value);
		printf("\n");
	}
	else {
		printf("OVERFLOW");
		printf("\n");
	}
	return (0);
}
