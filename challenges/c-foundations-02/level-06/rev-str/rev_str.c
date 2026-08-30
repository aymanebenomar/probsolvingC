char *rev_str(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	i--;

	int f = 0;
	char tmp;

	while (f < i)
	{
		tmp = str[f];
		str[f] = str[i];
		str[i] = tmp;
		f++;
		i--;
	}
	return (str);
}
