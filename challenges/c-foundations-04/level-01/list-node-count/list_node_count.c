#include <stddef.h>

typedef struct ListNode
{
	void          *data;
	struct ListNode *next;
} ListNode;

int	list_node_count(ListNode *head)
{
	int	count;

	count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}
