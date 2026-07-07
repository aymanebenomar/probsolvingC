int	isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
	{
		return (1);
	}
	else
	{
		return 0;
	}
}
