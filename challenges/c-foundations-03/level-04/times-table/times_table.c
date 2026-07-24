#include <unistd.h>

int	ft_atoi(char *str)
{
	int	number;
	int	i;

	number = 0;
	i = 0;
	while (str[i])
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	n;
	int	i;

	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	n = ft_atoi(argv[1]);
	i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(i * n);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}