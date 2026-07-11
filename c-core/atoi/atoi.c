int atoi(const char *str)
{
	int i = 0;
	int result = 0;
	int sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result *= sign;
	return (result);
}

/* #include <stdio.h>
int main(void)
{
	printf("%d\n", atoi(" +7"));
	printf("%d\n", atoi("-300"));
	printf("%d\n", atoi("nope"));
	return 0;
} */
