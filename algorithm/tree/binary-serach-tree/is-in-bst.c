#include <stdio.h>

#include "../../include/tree/binary-tree.h"
#include "../../include/tree/binary-serach-tree.h"

int is_in_bst(struct tree_node *root, int target)
{
	if (root == NULL) {
		return 0;
	}

	if (root->val == target) {
		return 1;
	}

	if (root->val > target) {
		return is_in_bst(root->left, target);
	}

	if (root->val < target) {
		return is_in_bst(root->right, target);
	}
}
