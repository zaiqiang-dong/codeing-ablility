#include <stdio.h>
#include "binary-tree.h"


#define ARRAY_SIZE 100

int main(int argc, char *argv[])
{

 	int sbuff[ARRAY_SIZE] = {'\0'};
	struct tree_node *root = NULL;
	sbuff[0] = 1;
	sbuff[1] = 2;
	sbuff[2] = '#';
	sbuff[3] = 4;
	sbuff[4] = '#';
	sbuff[5] = '#';
	sbuff[6] = 3;
	sbuff[7] = '#';
	sbuff[8] = '#';

	root = reserialize(sbuff);
	pre_order_traverse(root);

	serialize(root,sbuff);

	return 0;
}
