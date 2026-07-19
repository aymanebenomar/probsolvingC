#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	long long timeout;
	long long distance;
	long long reach;

	if (argc != 3)
	{
		printf("wrong number of arguments\n");
		return (1);
	}
	timeout = atol(argv[1]);
	distance = atol(argv[2]);
	reach = 299792458LL * timeout / 1000000;
	printf("%lld\n", reach);
	if (distance <= reach)
		printf("delivered\n");
	else 
		printf("bounced\n");
	return (0);
}
