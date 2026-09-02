unsigned int gcd(unsigned int a, unsigned int b)
{
	unsigned int i;

	if (a > b)
		i = b;
	else
		i = a;
	while (i > 0)
	{
		if (a % i == 0 && b % i == 0)
			return (i);
		i--;
	}
	return (0);
}

unsigned int lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);

	unsigned int res = a / gcd(a, b) * b;
	return (res);
}

