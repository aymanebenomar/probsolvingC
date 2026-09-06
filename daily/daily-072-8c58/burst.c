int	longest_run(const char *line)
{
	int	i;
	int	run;
	int max;

	if (!line[0])
		return (0);
	max = 1;
	i = 0;
	run = 1;
	while (line[i])
	{
		if (line[i] == line[i + 1])
		{
			run++;
			if (run > max)
				max = run;
		}
		else
			run = 1;
		i++;
	}
	return (max);
}
