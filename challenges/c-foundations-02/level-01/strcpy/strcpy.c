char	*strcpy(char *dst, const char *src)
{
	char *p = dst;
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (p);
}
