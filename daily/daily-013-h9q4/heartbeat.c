// Return how many bytes are safe to echo: requested, but only when it fits
// in received. If requested is negative or bigger than received, return 0.
int	bytes_to_echo(int requested, int received)
{
	if (requested >= 0 && requested <= received)
		return requested;
	return (0);
}
