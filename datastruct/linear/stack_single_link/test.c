#include <stdlib.h>
#include <stdio.h>
#include "./stack_single_link.h"

void main(){
	int tmp = 0;
	int ret = 0;
	int i = 0;
	int size = 0;
	struct single_link_stack *stack = creat_single_link_stack();
	single_link_stack_push(stack, 4);
	single_link_stack_push(stack, 322);
	single_link_stack_push(stack, 43);
	single_link_stack_push(stack, 5);
	single_link_stack_push(stack, 53);
	single_link_stack_push(stack, 56666);

	size = single_link_stack_size(stack);

	printf("stack size = %d.\n", size);

	for ( i = 0; i < size; i++) {
		tmp = single_link_stack_pop(stack, &ret);
		printf("pop ret = %d, val = %d.\n", tmp, ret);
	}

}

