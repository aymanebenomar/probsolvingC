char	*strcat(char *dst, const char *src)
{
	char *first = dst;
	while (*dst)
		dst++;
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (first);
}
