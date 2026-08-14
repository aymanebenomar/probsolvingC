int	trusted_aoa(int left, int right, int tolerance)
{
	int diff;

	diff = left - right;
	if (diff < 0)
		diff = -diff;
	if (diff > tolerance)
		return (-1);
	return ((left + right) / 2);
}
