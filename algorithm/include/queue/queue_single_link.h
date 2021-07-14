/*
 * queue implement with single link
 *
 */

#include "../single_link/single_link.h"

struct single_link_queue {
    struct single_link *link;
};

struct single_link_queue * create_single_link_queue();
int single_link_queue_is_empty(struct single_link_queue *queue);
void single_link_queue_put(struct single_link_queue *queue, int val);
int single_link_queue_get(struct single_link_queue *queue, int *ret);
