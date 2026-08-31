#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("wrong number of arguments\n");
		return 0;
	}
	
	int n1 = atoi(av[1]);
	int n2 = atoi(av[2]);
	int i;

	if (n1 > n2)
		i = n2;
	else
		i = n1;

	while (i >= 1)
	{
		if (n1 % i == 0 && n2 % i == 0)
		{
			printf("%d", i);
			printf("\n");
			return 0;
		}
		i--;
	}
	return (0);
}
