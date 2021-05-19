#include <stdio.h>
#include "binary-serach-tree.h"


int is_in_bst(struct TreeNode *root, int target){
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