int	isalpha(int c)
{
	unsigned char check = (unsigned char)c;
	if ((check >= 'a' && check <= 'z') || (check >= 'A' && check <= 'Z'))
	{
		return (1);
	}
	else 
	{
		return (0);
	}
}
