
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 反转链表前n个

struct ListNode *last_n = NULL;

struct ListNode * reversen(struct ListNode *head, int n)
{
	if (n == 1) {
		last_n = head->next;
	}

	struct ListNode *last = reversen(head->next, n-1);

	head->next->next = head;
	head->next = last_n;

	return last;

}
