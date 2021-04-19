
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 struct ListNode {
     int val;
     struct ListNode *next;
 };

// 递代反转整个链表

struct ListNode * reverse(struct ListNode *head)
{
	struct ListNode *pre;
	struct ListNode *cur;
	struct ListNode *nxt;

	pre = NULL;
	cur = head;
	nxt = head;

	while (cur != NULL) {
		/* save cur->next */
		nxt = cur->next;

		cur->next = pre;
		pre = cur;

		/* reset cur */
		cur = nxt;
	}

}


/* 迭代反转从head 到 n */

struct ListNode * reverse_n(struct ListNode *head, struct ListNode *n)
{
	struct ListNode *pre;
	struct ListNode *cur;
	struct ListNode *nxt;
	pre = NULL;
	cur = head;
	nxt = head;

	while (cur != n) {
		/* 保存 cur->next */
		nxt = cur->next;

		cur->next = pre;
		pre = cur;

		/* 恢复 cur */
		cur = nxt;
	}

}

/* 迭代反转，以k个为一级 */

struct ListNode * reverse_kgroup(struct ListNode *head, int k)
{
	struct ListNode *a;
	struct ListNode *b;
	int i;

	if (head == NULL) {
		return NULL;
	}

	a = b = head;

	for (i = 0; i < k; i++) {
		/* 整个递归结束条件 */
		if(b == NULL)
			return head;
		b = b->next;
	}

	/* 反转部分 */
	struct ListNode *new_head = reverse_n(a, b);
	/* 递归反转 */
	a->next = reverse_kgroup(b, k);
	return new_head;

}

