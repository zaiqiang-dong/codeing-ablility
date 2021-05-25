#include <stdio.h>
#include "../datastruct/binary-tree.h"

struct TreeNode * get_min(struct TreeNode *root) {
	while (root->left) {
		root = root->left;
	}
	return root;
}

struct TreeNode * delete_from_bst(struct TreeNode *root, int target){
	if (root == NULL) {
		return NULL;
	}

	if (root->val == target) {
		/* 处理叶子节点或者只有左子树或者右子树的情况 */
		if (root->left == NULL) {
			return root->right;
		}
		if (root->right == NULL) {
			return root->left;
		}

		/* 处理左右子树都不为空情况 */
		struct TreeNode *min = get_min(root->right);
		root->val = min->val;
		/* 继续删除找到的min */
		root->right = delete_from_bst(root->right, min->val);
	} else if (root->val > target) {
		root->left = delete_from_bst(root->left, target);
	} else if (root->val < target) {
		root->right = delete_from_bst(root->right, target);
	}
}
