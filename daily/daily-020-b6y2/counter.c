// Return 1 while centiseconds still fits in a signed 32-bit integer
// (max 2147483647), or 0 once it would overflow.
int	counter_ok(long centiseconds)
{
	if (centiseconds <= 2147483647)
		return (1);
	return (0);
}
