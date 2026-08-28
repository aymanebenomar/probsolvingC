unsigned char swap_bits(unsigned char byte)
{
	return ((byte >> 4) | (byte << 4));
}
