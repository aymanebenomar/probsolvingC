char *find_any_char(const char *text, const char *needles)
{
	int i;
	int x = 0;

	while(text[x])
	{
		i = 0;
		while (needles[i])
		{
			if (text[x] == needles[i])
				return((char *)&text[x]);
			i++;
		}
		x++;
	}
	return (0);
}

