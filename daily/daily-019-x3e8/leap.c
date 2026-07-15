// feb_days returns 29 in a leap year, else 28. The rule below treats every
// year divisible by 4 as leap, so it invents Feb 29, 1900. Fix it: a century
// is leap only when divisible by 400.
int	feb_days(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return (29);
	return (28);
}
