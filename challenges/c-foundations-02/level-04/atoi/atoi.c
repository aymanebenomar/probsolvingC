int atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;

	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}

	while (*str >= '0' && *str <= '9')
	{
		char c = *str;
		result = (result * 10) + (c  - '0');
		str++;
	}
	return (result * sign);
}