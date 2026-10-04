// power(base, exp) is base * power(base, exp - 1), with power(base, 0) equal to 1.
// A negative exp is outside the domain: return -1.
int	power(int base, int exp)
{
	if (exp == 0)
		return (1);
	if (exp < 0)
		return (-1);
	return (base * power(base, exp - 1));
}
