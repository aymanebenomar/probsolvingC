#include <unistd.h>

int	main(void)
{
	char nums = '9';
	while (nums >= '0')
	{
		write(1, &nums, 1);
		nums--;
	}
	write(1, "\n", 1);
	return (0);
}
