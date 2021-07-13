#include "../include/binary-tree.h"
#include <math.h>


int count_node_btree(struct tree_node *root){
	struct tree_node * l = root;
	struct tree_node * r = root;
	int hl = 0;
	int hr = 0;
	if (root == NULL) {
		return 0;
	}

	while (l->left) {
		l = l->left;
		hl++;
	}

	while (r->right) {
		r = r->right;
		hr++;
	}

	if (hl == hr) {
		return (int)pow(2, (double)hl);
	}

	return 1 + count_node_btree(root->left) + count_node_btree(root->right);
}
