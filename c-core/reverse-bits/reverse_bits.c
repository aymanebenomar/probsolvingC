unsigned char	reverse_bits(unsigned char byte)
{
	int				i;
	unsigned char	result;

	i = 0;
	result = 0;
	while (i < 8)
	{
		result = (result << 1) | (byte & 1);
		byte = byte >> 1;
		i++;
	}
	return (result);
}