#include "../single_link/single_link.h"

struct single_link_stack{
    struct single_link *link;
};

struct single_link_stack *creat_single_link_stack();
void single_link_stack_push(struct single_link_stack *stack, int val);
int single_link_stack_pop(struct single_link_stack *stack, int *ret);
int single_link_stack_size(struct single_link_stack *stack);
int single_link_stack_is_empty(struct single_link_stack *stack);
