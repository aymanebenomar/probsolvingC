#include <stddef.h>

void	*memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t i = 0;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (n == 0)
		return (d);
	while(i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
