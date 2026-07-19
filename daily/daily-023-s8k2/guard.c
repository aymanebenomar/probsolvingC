int	safe_rm_target(const char *root)
{
	int i = 0;

	if(root == 0)
		return 0;
	
	while(root[i])
	{
		if (root[i] != '/')
			return 1;
		i++;
	}
	return (0);
}
