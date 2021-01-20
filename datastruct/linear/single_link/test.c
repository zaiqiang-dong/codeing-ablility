#include <stdio.h>
#include "single_link.h"

int main(){
	int find_result = 0;
	struct single_link *link = create_single_link();

	/* single_link_insert_head(link, 10); */
	/* single_link_insert_head(link, 20); */
	/* single_link_insert_head(link, 30); */
	/* single_link_insert_head(link, 40); */

	single_link_insert_tail(link, 0);
	single_link_insert_tail(link, 10);
	single_link_insert_tail(link, 22);
	single_link_insert_tail(link, 34);
	single_link_insert_tail(link, 44);
	single_link_insert_tail(link, 55);
	single_link_insert_tail(link, 65);
	single_link_insert_tail(link, 756);
	single_link_insert_tail(link, 83);
	single_link_insert_tail(link, 95);

	printf("link size = %d.\n", single_link_size(link));

	printf("find val = %d , find_result = %d.\n", 20,
			single_link_find(link, 20));

	printf("find val = %d , find_result = %d.\n", 10,
			single_link_find(link, 10));

	single_link_delete_node(link, 20);
	printf("link size = %d.\n", single_link_size(link));
	printf("\n");

	printf("traveler single link \n");
	while (link->head) {
		printf("node val = %d.\n",link->head->val);
		link->head = link->head->next;
	}
}
