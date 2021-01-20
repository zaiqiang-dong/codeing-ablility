#include <stdio.h>
#include "queue_single_link.h"


int main(){
	int i = 0;
	int tmp_val = 0;
	struct single_link_queue *queue = create_single_link_queue();

	for (i = 0; i < 10; i++) {
		single_link_queue_put(queue, i);
	}

	while (single_link_queue_is_empty(queue)) {
		single_link_queue_get(queue, &tmp_val);
		printf("Get val form queue = %d.\n", tmp_val);
	}
}
