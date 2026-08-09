// sum_to_n(n) is n + sum_to_n(n - 1), with sum_to_n(0) equal to 0.
// A negative n is invalid: return -1.
int	sum_to_n(int n)
{
	if (n < 0)
		return(-1);
	if (n == 0)
		return 0;
	return (n + sum_to_n(n - 1));
}
