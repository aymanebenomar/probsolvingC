char *rev_str(char *str)
{
	int i = 0;
	char temp;
	int len = 0;

	while (str[len])
		len++;
	len--;
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
	return (str);
}
