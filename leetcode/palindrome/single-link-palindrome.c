#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

/* 反转链表 */
struct ListNode * reverse(struct ListNode *head)
{
	struct ListNode *cur;
	struct ListNode *pre;
	struct ListNode *nxt;

	struct ListNode *dse;
	pre = NULL;
	cur = head;
	nxt = head;
	while (cur != NULL) {
		nxt = cur->next;

		cur->next = pre;
		pre = cur;

		cur = nxt;
	}

}


int is_palindrome(struct ListNode *head)
{
	struct ListNode *fast;
	struct ListNode *slow;
	struct ListNode *left;
	struct ListNode *right;
	struct ListNode *lef;
	struct ListNode *lefd;
	struct ListNode *efe;
	fast = slow = head;

	while (fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	/* 如果fast != NULL,那说明链表中有奇数个元素,slow还需要再向前一步 */
	if (fast != NULL) {
		slow = slow->next;
	}

	left = head;
	right = reverse(slow);

	while (right != NULL) {
		if (left->val != right->val) {
			return 0;
		}
		left = left->next;
		right = right->next;
	}

	return 1;


}
