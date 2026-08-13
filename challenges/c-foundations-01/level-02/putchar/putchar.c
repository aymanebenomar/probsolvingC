#include <unistd.h>

int	putchar(int c)
{
	char al = (unsigned char)c;
	write(1, &al, 1);
	return (c);
}
