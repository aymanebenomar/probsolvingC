#include <unistd.h>

int atoa(char *s)
{
	int i = 0;
	int result = 0;
	int sign = 1;

	while (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	return (result * sign);
}

void putn(int n)
{
	char c;

	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	
	if (n > 9)
		putn(n / 10);
	c = (n % 10) + '0';
	write (1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		write (1, "0\n", 2);
		return 0;
	}
	int i = 1;
	int sum = 0;

	while (i < ac)
	{
		sum += atoa(av[i]);
		i++;
	}

	putn(sum);
	write(1, "\n", 1);
	return (0);
}
