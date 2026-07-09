char	*strrchr(const char *s, int c)
{
	int i = 0;
	char *last = 0;
	
	while(s[i])
	{
		if (s[i] == (char)c)
			last = (char *)&s[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (last);
}