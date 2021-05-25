#include <stdio.h>
#include <stdlib.h>

#include "../datastruct/binary-tree.h"


struct TreeNode * insert_to_bst(struct TreeNode *root, int target){
	if (root == NULL) {
		return (struct TreeNode *)malloc(sizeof(struct TreeNode));
	}

	if (root->val < target) {
		root->right = insert_to_bst(root->right, target);
	}
	if (root->val > target) {
		root->left = insert_to_bst(root->left, target);
	}
	return root;
}
