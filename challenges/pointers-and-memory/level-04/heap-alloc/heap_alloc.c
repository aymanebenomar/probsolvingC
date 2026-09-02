#include <stddef.h>

#define POOL_SIZE	4096

typedef struct s_block
{
	size_t			size;	/* payload capacity in bytes (multiple of 8) */
	size_t			free;	/* 1 if free, 0 if in use */
	struct s_block	*next;	/* next block in memory order, NULL if last */
}	t_block;

#define ALIGN8(x)	(((x) + 7) & ~(size_t)7)
#define HEADER_SIZE	ALIGN8(sizeof(t_block))

static _Alignas(8) unsigned char	pool[POOL_SIZE];
static t_block						*head = NULL;
static int							initialized = 0;

static void	init_pool(void)
{
	head = (t_block *)pool;
	head->size = POOL_SIZE - HEADER_SIZE;
	head->free = 1;
	head->next = NULL;
	initialized = 1;
}

static void	split_block(t_block *b, size_t need)
{
	t_block	*rest;

	if (b->size >= need + HEADER_SIZE + 8)
	{
		rest = (t_block *)((unsigned char *)b + HEADER_SIZE + need);
		rest->size = b->size - need - HEADER_SIZE;
		rest->free = 1;
		rest->next = b->next;
		b->size = need;
		b->next = rest;
	}
}

void	*heap_alloc(size_t n)
{
	t_block	*cur;
	size_t	need;

	if (!initialized)
		init_pool();
	if (n == 0)
		return (NULL);
	if (n > POOL_SIZE)
		return (NULL);
	need = ALIGN8(n);
	cur = head;
	while (cur != NULL)
	{
		if (cur->free && cur->size >= need)
		{
			split_block(cur, need);
			cur->free = 0;
			return ((unsigned char *)cur + HEADER_SIZE);
		}
		cur = cur->next;
	}
	return (NULL);
}

static t_block	*find_prev(t_block *target)
{
	t_block	*cur;

	cur = head;
	if (cur == target)
		return (NULL);
	while (cur != NULL)
	{
		if (cur->next == target)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

void	heap_free(void *p)
{
	t_block	*b;
	t_block	*prev;

	if (!initialized)
		init_pool();
	if (p == NULL)
		return ;
	b = (t_block *)((unsigned char *)p - HEADER_SIZE);
	b->free = 1;
	if (b->next != NULL && b->next->free)
	{
		b->size += HEADER_SIZE + b->next->size;
		b->next = b->next->next;
	}
	prev = find_prev(b);
	if (prev != NULL && prev->free)
	{
		prev->size += HEADER_SIZE + b->size;
		prev->next = b->next;
	}
}