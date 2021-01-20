#include <malloc.h>
#include "single_link.h"


struct single_link * create_single_link(){
    struct single_link * link = (struct single_link *)malloc(sizeof(
				struct single_link));
	link->len = 0;
	link->head = link->tail = NULL;
	return link;
}

struct single_link_node * create_single_link_node(){
    return (struct single_link_node *)malloc(sizeof(struct single_link_node));

}

void single_link_insert_head(struct single_link *link, int val){
	struct single_link_node *new_node = create_single_link_node();
	new_node->val = val;
	if(link->len > 0){
		new_node->next = link->head;
		link->head = new_node;
	} else {
		new_node->next = NULL;
		link->head = link->tail = new_node;
	}
	link->len++;
}

void single_link_insert_tail(struct single_link *link, int val){
	struct single_link_node *new_node = create_single_link_node();
	new_node->val = val;
	new_node->next = NULL;
	if (link->len != 0) {
		link->tail->next = new_node;
		link->tail = new_node;
	} else {
		link->head = link->tail = new_node;
	}
	link->len++;
}

int single_link_find(struct single_link *link, int val){
	struct single_link_node *head = link->head;
	while (head && head->val != val) {
		head = head->next;
	}

	return head != NULL;
}

void single_link_delete_node(struct single_link *link, int val){
	struct single_link_node *p = NULL;
	struct single_link_node *c = link->head;
	while (c && c->val != val) {
		p = c;
		c = c->next;
	}
	if (c) {
		if (p) {
			p->next = c->next;
			if (c->next == NULL) {
				link->tail = p;
			}
		} else {
			link->head = c->next;
			if (c->next == NULL) {
				link->tail = link->head;
			}
		}
		free(c);
		link->len--;
	}
}

int single_link_size(struct single_link *link) {
	return link->len;
}

int single_link_is_empty(struct single_link *link){
	return link->len == 0;
}

void single_link_destory(struct single_link *link){
	struct single_link_node *head = link->head;
	while (head) {
		head = head->next;
		free(head);
	}
	free(link);
}
