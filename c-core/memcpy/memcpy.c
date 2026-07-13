#include <stddef.h>

void	*gm_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char 	*source = src;
	unsigned char 	*dest = dst;
	size_t 	i = 0;

	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}


/* #include <stdio.h>
int main(void)
{
	char dst[20];
	gm_memcpy(dst, "rebase --hard", 4);
	printf("%s", dst);
	return 0;
} */