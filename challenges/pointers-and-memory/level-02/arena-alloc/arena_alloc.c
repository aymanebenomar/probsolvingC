#include <stddef.h>

#define POOL_SIZE 4096

static _Alignas(8) unsigned char pool[POOL_SIZE];
static size_t offset = 0;

void	*arena_alloc(size_t n)
{
	size_t	rounded;
	void	*ptr;

	if (n == 0)
		return (NULL);
	if (n > POOL_SIZE)
		return (NULL);
	rounded = (n + 7) & ~(size_t)7;
	if (rounded > POOL_SIZE - offset)
		return (NULL);
	ptr = &pool[offset];
	offset += rounded;
	return (ptr);
}

void	arena_reset(void)
{
	offset = 0;
}