int	excel_mangles(const char *name)
{
	char *months;

	int i;
	int j;

	months = "JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC";
	i = 0;
	while (i < 36)
	{
		if(name[0] == months[i]
			&& name[1] == months[i + 1]
			&& name[2] == months[i + 2])
		{
			if (!name[3])
				return (0);
			j = 3;
			while(name[j])
			{
				if (name[j] < '0' || name[j] > '9')
					return (0);
				j++;
			}
			return (1);
		}
		i += 3;
	}
	return (0);
}
