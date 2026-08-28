#include <unistd.h>
#include <stdarg.h>

void	put_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	put_str(char *str, int *count)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		put_char(str[i], count);
		i++;
	}
}

void	put_nbr(int n, int *count)
{
	if (n == -2147483648)
	{
		put_str("-2147483648", count);
		return;
	}
	if (n < 0)
	{
		put_char('-', count);
		n = -n;
	}
	if (n >= 10)
		put_nbr(n / 10, count);
	put_char((n % 10) + '0', count);
}

void	put_hex(unsigned int n, int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		put_hex(n / 16, count);
	put_char(hex[n % 16], count);
}

int	mini_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				put_char((char)va_arg(ap, int), &count);
			else if (format[i] == 's')
				put_str(va_arg(ap, char *), &count);
			else if (format[i] == 'd')
				put_nbr(va_arg(ap, int), &count);
			else if (format[i] == 'x')
				put_hex(va_arg(ap, unsigned int), &count);
			else if (format[i] == '%')
				put_char('%', &count);
			else
			{
				put_char('%', &count);
				put_char(format[i], &count);
			}
		}
		else
			put_char(format[i], &count);
		i++;
	}
	va_end(ap);
	return (count);
}
