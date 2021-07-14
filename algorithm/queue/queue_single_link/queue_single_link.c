#include "queue_single_link.h"
#include <malloc.h>

struct single_link_queue * create_single_link_queue(){
    struct single_link_queue * queue = (struct single_link_queue *)malloc(
            sizeof(struct single_link_queue));
    queue->link = create_single_link();
	return queue;
}

int single_link_queue_is_empty(struct single_link_queue *queue){
    return single_link_is_empty(queue->link) == 0;
}

void single_link_queue_put(struct single_link_queue *queue, int val){
    single_link_insert_tail(queue->link, val);
}


int single_link_queue_get(struct single_link_queue *queue, int *ret){
    struct single_link *link = queue->link;
    if(single_link_is_empty(link)){
        return 0;
    } else {
        *ret = link->head->val;
        single_link_delete_node(link, *ret);
    }
}
