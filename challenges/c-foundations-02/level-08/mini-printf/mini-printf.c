#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

static int	put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	put_str(const char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}

static int	put_nbr(int n)
{
	unsigned int	nb;
	int				count;

	count = 0;
	if (n < 0)
	{
		count += put_char('-');
		nb = 0u - (unsigned int)n;
	}
	else
		nb = (unsigned int)n;
	if (nb >= 10)
		count += put_nbr(nb / 10);
	count += put_char((nb % 10) + '0');
	return (count);
}

static int	put_hex(unsigned int n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += put_hex(n / 16);
	count += put_char(base[n % 16]);
	return (count);
}

int	mini_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
			count += put_char(format[i]);
		else
		{
			i++;
			if (format[i] == 'c')
				count += put_char(va_arg(ap, int));
			else if (format[i] == 's')
				count += put_str(va_arg(ap, char *));
			else if (format[i] == 'd')
				count += put_nbr(va_arg(ap, int));
			else if (format[i] == 'x')
				count += put_hex(va_arg(ap, unsigned int));
			else if (format[i] == '%')
				count += put_char('%');
			else if (format[i])
			{
				count += put_char('%');
				count += put_char(format[i]);
			}
			else
				count += put_char('%');
		}
		i++;
	}
	va_end(ap);
	return (count);
}