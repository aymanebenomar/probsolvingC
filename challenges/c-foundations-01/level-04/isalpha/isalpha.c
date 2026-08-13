int	isalpha(int c)
{
	char alpha = (char)c;
	if ((alpha >= 'a' && alpha <= 'z') != (alpha >= 'A' && alpha <= 'Z'))
		return (1);
	return (0);
}
