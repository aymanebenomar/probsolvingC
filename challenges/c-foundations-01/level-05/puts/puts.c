#include <unistd.h>

int	puts(const char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	if (*s == '\0')
	{
		write(1, "\n", 1);
		return (1);
	}
	
	return (-1);
}
