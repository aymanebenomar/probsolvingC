int	reachable(const int *base, const int *size, int n, int addr)
{
	int i = 0;
	while (i < n)
	{
		if (size[i] > 0 && base[i] <= addr && addr <= base[i] + size[i] - 1)
			return (1);
		i++;
	}
	return (0);
}
