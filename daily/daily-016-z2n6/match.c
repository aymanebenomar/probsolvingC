// Match text against pattern. '*' matches any run of characters (even empty);
// every other character must match exactly. Return 1 on a full match, else 0.
int	wildcard_match(const char *pattern, const char *text)
{
	const char *star = 0;
	const char *saved_text = 0;

	while(*text)
	{
		if (*pattern == *text)
		{
			pattern++;
			text++;
		}
		else if (*pattern == '*')
		{
			star = pattern;
			pattern++;
			saved_text = text;
		}
		else if (star != 0)
		{
			pattern = star + 1;
			saved_text++;
			text = saved_text;
		}
		else 
			return 0;
	}

	while (*pattern == '*')
		pattern++;
	return (*pattern == '\0');
}
