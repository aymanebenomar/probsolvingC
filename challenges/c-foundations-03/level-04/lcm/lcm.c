int gcd(unsigned int a, unsigned int b)
{
	int div;
	if (a < b)
		div = a;
	else 
		div = b;

	while (div >= 1)
	{
		if (a % div == 0 && b % div == 0)
			return (div);
		div--;
	}
	return (1);
}


unsigned int lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return 0;

	unsigned int n = a / gcd(a, b) * b;
	return (n);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d", lcm(5, 7));
// 	return 0;
// }
