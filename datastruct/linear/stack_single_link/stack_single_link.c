#include "./stack_single_link.h"
#include <stdlib.h>

struct single_link_stack *creat_single_link_stack(){
	struct single_link_stack * stack = (struct single_link_stack *)malloc(
				sizeof(struct single_link_stack));
	stack->link = create_single_link();
	return stack;
}
void single_link_stack_push(struct single_link_stack *stack, int val){
	single_link_insert_head(stack->link, val);
}

int single_link_stack_pop(struct single_link_stack *stack, int *ret){
	if (single_link_is_empty(stack->link)) {
		return -1;
	} else {
		*ret = stack->link->head->val;
		single_link_delete_node(stack->link, *ret);
	}
	return 1;
}

int single_link_stack_size(struct single_link_stack *stack){
	return single_link_size(stack->link);
}

int single_link_stack_is_empty(struct single_link_stack *stack){
	return single_link_is_empty(stack->link);
}
