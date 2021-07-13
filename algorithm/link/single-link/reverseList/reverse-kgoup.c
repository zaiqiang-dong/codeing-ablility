#include "../../../include/link/single-link.h"
// 递代反转整个链表

struct single_link_node * reverse(struct single_link_node *head)
{
	struct single_link_node *pre;
	struct single_link_node *cur;
	struct single_link_node *nxt;

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

struct single_link_node * reverse_n(struct single_link_node *head, struct single_link_node *n)
{
	struct single_link_node *pre;
	struct single_link_node *cur;
	struct single_link_node *nxt;
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

struct single_link_node * reverse_kgroup(struct single_link_node *head, int k)
{
	struct single_link_node *a;
	struct single_link_node *b;
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
	struct single_link_node *new_head = reverse_n(a, b);
	/* 递归反转 */
	a->next = reverse_kgroup(b, k);
	return new_head;

}

