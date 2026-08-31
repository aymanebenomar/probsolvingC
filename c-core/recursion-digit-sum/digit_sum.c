int	digit_sum(int n)
{
	long nb = n;
	if (nb < 0)
		nb = -nb;

	int result = 0;
	while (nb > 0)
	{
		result += nb % 10;
		nb /= 10;
	}
	return (result);
}