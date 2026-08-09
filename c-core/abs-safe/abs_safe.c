// Return the absolute value of n as a long.
// Widen to long before negating, never after.
long	abs_safe(int n)
{
	long nb = n;
	if (nb < 0)
		nb *= -1;
	return (nb);
}
