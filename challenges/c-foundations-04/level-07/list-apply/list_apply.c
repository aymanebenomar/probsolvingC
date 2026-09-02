#include "list.h"
#include <stddef.h>

void	list_apply(ListNode *list, void (*f)(void *))
{
	while (list != NULL)
	{
		f(list->data);
		list = list->next;
	}
}

// int main ()
// {
// 	int a;
// 	int b;
// 	int c;

// 	a = 7;
// 	b = 8;
// 	c = 9;

// 	ListNode n1;
// 	ListNode n2;
// 	ListNode n3;

// 	n1.data = &a;
// 	n1.next = &n2;
// 	n2.data = &b;
// 	n2.next = &n3;
// 	n3.data = &c;
// 	n3.next = NULL;
	
// 	list_apply(&n1, &f);
// }