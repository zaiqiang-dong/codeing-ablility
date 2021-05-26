#include <stdio.h>
#include <stdlib.h>

#include "binary-tree.h"
#include "binary-serach-tree.h"

struct tree_node * insert_to_bst(struct tree_node *root, int target)
{
	if (root == NULL) {
		return (struct tree_node *)malloc(sizeof(struct tree_node));
	}

	if (root->val < target) {
		root->right = insert_to_bst(root->right, target);
	}
	if (root->val > target) {
		root->left = insert_to_bst(root->left, target);
	}
	return root;
}
