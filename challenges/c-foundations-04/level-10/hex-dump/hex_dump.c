#include <unistd.h>

static void	write_hex_digit(unsigned char val)
{
	char	c;

	if (val < 10)
		c = '0' + val;
	else
		c = 'a' + (val - 10);
	write(1, &c, 1);
}

static void	write_hex_byte(unsigned char byte)
{
	write_hex_digit(byte / 16);
	write_hex_digit(byte % 16);
}

static void	write_ascii(unsigned char *row, unsigned int count)
{
	unsigned int	i;
	char			c;

	i = 0;
	while (i < count)
	{
		if (row[i] >= 32 && row[i] <= 126)
			c = row[i];
		else
			c = '.';
		write(1, &c, 1);
		i++;
	}
}

static void	write_row(unsigned char *row, unsigned int count)
{
	unsigned int	i;

	i = 0;
	while (i < count)
	{
		write_hex_byte(row[i]);
		write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "   ", 3);
		i++;
	}
	write(1, " ", 1);
	write_ascii(row, count);
	write(1, "\n", 1);
}

void	*hex_dump(void *addr, unsigned int size)
{
	unsigned char	*bytes;
	unsigned int	i;
	unsigned int	remaining;

	bytes = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		remaining = size - i;
		if (remaining > 16)
			remaining = 16;
		write_row(bytes + i, remaining);
		i += remaining;
	}
	return (addr);
}