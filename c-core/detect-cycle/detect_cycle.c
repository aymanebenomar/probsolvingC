#include "list.h"
#include <stddef.h>

int	detect_cycle(ListNode *list)
{
	ListNode *slow;
	ListNode *fast;

	slow = list;
	fast = list;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}