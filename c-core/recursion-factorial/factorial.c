// factorial(n) is n * factorial(n - 1), with factorial(0) equal to 1.
// A negative n is an invalid reading: return -1.
int	factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return 1;
	return (n * factorial(n - 1));
}
