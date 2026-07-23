int	reassembled_ok(int offset, int len)
{
	if (offset > 65535)
		return (0);
	if (len > 65535 - offset)
		return (0);
	return (1);
}
