// Return 1 when value can be stored in an int without changing,
// 0 when the conversion would lose information.
int	fits_in_int(long value)
{
	if (value == -2147483648)
		return (1);
	if (value <= 2147483647 && value >= -2147483647)
		return (1);
	return (0);
}
