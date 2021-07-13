#include "../../../include/link/single-link.h"

// 递归反转整个链表

struct single_link_node * reverse(struct single_link_node *head)
{
	if (head->next == NULL) {
		return head;
	}

	struct single_link_node *last = reverse(head->next);

	head->next->next = head;
	head->next = NULL;

	return last;

}

// 递归反转链表前n个

struct single_link_node *last_n = NULL;

struct single_link_node * reversen(struct single_link_node *head, int n)
{
	if (n == 1) {
		last_n = head->next;
	}

	struct single_link_node *last = reversen(head->next, n-1);

	head->next->next = head;
	head->next = last_n;

	return last;

}


// 递归反转链表从m到n

struct single_link_node * reverse_between(struct single_link_node *head, int m, int n)
{
	if(m == 1){
		return reversen(head, n);
	}

	head->next = reverse_between(head, m-1, n-1);
	return head;
}
