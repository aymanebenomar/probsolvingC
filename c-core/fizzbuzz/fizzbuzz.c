#include <unistd.h>
void putnbr(int n)
{
	char c;
	if (n > 9)
		putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int num = 1;
	while (num <= 100)
	{
		if (num % 15 == 0)
			write(1, "FizzBuzz", 8);
		else if (num % 5 == 0)
			write(1, "Buzz", 4);
		else if (num % 3 == 0)
			write(1, "Fizz", 4);
		else {
			putnbr(num);
		}
		write(1, "\n", 1);
		num++;
	}
	return (0);
}
