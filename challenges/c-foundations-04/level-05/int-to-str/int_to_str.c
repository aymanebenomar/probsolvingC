#include <stdlib.h>

long lenn(long n)
{
	long result = 1;
	while (n > 9)
	{
		result++;
		n /= 10;
	}
	return (result);
}

char *int_to_str(int n)
{
	char *arr;
	long nb = n;
	long lennum = 0;
	int sign = 0;

	if (nb < 0)
	{
		nb = -nb;
		sign = 1;
	}
	lennum = lenn(nb);
	lennum += sign;
	arr = malloc((lennum + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	if (sign)
		arr[0] = '-';
	arr[lennum] = '\0';
	while (lennum > sign)
	{
		arr[--lennum] = (nb % 10) + '0';
		nb /= 10;
	}
	return (arr);
}

// #include <stdio.h>
// int main ()
// {
// 	char *s = int_to_str(-404);
// 	printf("%s", s);
// 	// printf("%d", lenn(404));
// 	return 0;
// }