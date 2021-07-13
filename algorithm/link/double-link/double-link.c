#include "../../include/link/double-link.h"
#include <malloc.h>


struct double_link_node *
inser_double_link_head(struct double_link_node *head, int data)
{
	struct double_link_node *new_node =
		(struct double_link_node *)malloc(sizeof(struct double_link_node));
	new_node->data = data;
	new_node->pre = NULL;
	new_node->next = head;
	head->pre = new_node;
	head = new_node;
	return head;
}

struct double_link_node *
inser_double_link_tail(struct double_link_node *head, int data)
{
	struct double_link_node *tmp = head;
	struct double_link_node *new_node =
		(struct double_link_node *)malloc(sizeof(struct double_link_node));
	new_node->data = data;
	new_node->next = NULL;
	while (tmp->next) {
		tmp = tmp->next;
	}
	tmp->next = new_node;
	new_node->pre = tmp;
	return head;


}

struct double_link_node *
inser_double_link_at(struct double_link_node *head, int data, int pos)
{
	int i = 0;
	int err = 0;
	struct double_link_node *tmp = head;
	struct double_link_node *new_node;
	if (pos == 1) {
		return inser_double_link_head(head, data);
	}
	new_node = (struct double_link_node *)malloc(sizeof(struct double_link_node));
	while (i < (pos - 1)) {
		if(tmp)
			tmp = tmp->next;
		else {
			err = 1;
			break;
		}
		i++;
	}

	if (!err) {
		tmp->next = new_node;
		new_node->next = NULL;
		new_node->pre = tmp;
	}

	return head;

}

struct double_link_node *
del_double_link(struct double_link_node *head, int data)
{
	struct double_link_node *tmp = head;
	while (tmp) {
		if(tmp->data == data) {
			tmp->pre->next = tmp->next;
			tmp->next->pre = tmp->pre;
			free(tmp);
			break;
		} else {
			tmp = tmp->next;
		}
	}
	return head;

}

