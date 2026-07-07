#include <unistd.h>

int	putchar(int c)
{
	unsigned char byte;

	byte = (unsigned char)c;
	write(1, &byte, 1);
	return (c);
}
