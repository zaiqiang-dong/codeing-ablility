
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 反转整个链表

struct ListNode * reverse(struct ListNode *head)
{
	if (head->next == NULL) {
		return head;
	}

	struct ListNode *last = reverse(head->next);

	head->next->next = head;
	head->next = NULL;

	return last;

}
