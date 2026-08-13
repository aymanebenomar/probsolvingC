char	*strcpy(char *dst, const char *src)
{
	char *s = dst;
	
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}

	*dst = '\0';
	return (s);
}
