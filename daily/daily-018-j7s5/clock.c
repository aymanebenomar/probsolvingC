// Convert a day count (day 1 = Jan 1, 1980) into its year.
// On day 366 of a leap year the loop never advances and hangs. Add that case.
int	is_leap(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int	year_from_days(int days)
{
	int	year;

	year = 1980;
	while (days > 365)
	{
		if (is_leap(year))
		{
			if (days > 366)
			{
				days -= 366;
				year++;
			}
			else
				return (year);
		}
		else
		{
			days -= 365;
			year++;
		}
	}
	return (year);
}
