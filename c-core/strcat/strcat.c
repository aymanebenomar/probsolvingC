char	*strcat(char *dst, const char *src)
{
	int x = 0;
	int i = 0;
	while (dst[i])
		i++;
	while(src[x])
	{
		dst[i] = src[x];
		i++;
		x++;
	}
	dst[i] = '\0';
	return (dst);
}
