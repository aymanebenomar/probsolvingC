int	toupper(int c)
{
	char check = (char)c;
	if (check >= 'a' && check <= 'z')
		return (c - 32);
	else if (check >= 'A' && check <= 'Z')
		return (c);
	else
		return (c);
}
