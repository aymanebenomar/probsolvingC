char *rev_str(char *str)
{
	int i = 0;
	int last = 0;
	char temp;

	while (str[last])
		last++;
	last--;

	while (i < last)
	{
		temp = str[last];
		str[last] = str[i];
		str[i] = temp;
		i++;
		last--;
	}
	return (str);
}
