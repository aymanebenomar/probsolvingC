#include "list.h"
#include <stdlib.h>
#include <stddef.h>

void	list_filter(ListNode **begin, void *ref, int (*cmp)(void *, void *))
{
	ListNode	*current;
	ListNode	*prev;
	ListNode	*tmp;

	if (*begin == NULL)
		return ;
	while (*begin != NULL && cmp((*begin)->data, ref) == 0)
	{
		tmp = *begin;
		*begin = (*begin)->next;
		free(tmp);
	}
	if (*begin == NULL)
		return ;
	prev = *begin;
	current = (*begin)->next;
	while (current != NULL)
	{
		if (cmp(current->data, ref) == 0)
		{
			tmp = current;
			prev->next = current->next;
			current = current->next;
			free(tmp);
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}