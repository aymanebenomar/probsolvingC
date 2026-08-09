int	digit_count(int n)
{
	int sum = 0;
	long nb = n;
	if (nb < 0)
		nb = -nb;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		sum++;
		nb /= 10;
	}
	return (sum);
}
