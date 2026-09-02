#include <unistd.h>

int atoa(char *s)
{
	int i = 0;
	int result = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	return (result);
}

void putn(int n)
{
	char c;
	if (n > 9)
		putn(n / 10);
	c = (n % 10) + '0';
	write (1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		write (1, "wrong number of arguments\n", 26);
		return 0;
	}

	int i = 1;
	int nun = atoa(av[1]);
	int sum = 0;
	while (i <= 9)
	{
		sum = i * nun;
		putn(i);
		write (1, " x ", 3);
		putn(nun);
		write (1, " = ", 3);
		putn(sum);
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
