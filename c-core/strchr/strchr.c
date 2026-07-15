char	*strchr(const char *s, int c)
{
	int i = 0;
	while(1)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

