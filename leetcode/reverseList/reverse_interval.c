
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

// 递归反转整个链表

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

// 递归反转链表前n个

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


// 递归反转链表从m到n

struct ListNode * reverse_between(struct ListNode *head, int m, int n)
{
	if(m == 1){
		return reversen(head, n);
	}

	head->next = reverse_between(head, m-1, n-1);
	return head;
}
