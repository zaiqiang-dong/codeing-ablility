
/* traverse  model */

#include <stdio.h>
#include "../datastruct/binary-tree.h"

void pre_order_traverse(struct TreeNode *root)
{
	/* 前序遍历 */
	if (root == NULL) {
		return;
	}
	printf("node->val = %d.\n", root->val);
	pre_order_traverse(root->left);
	pre_order_traverse(root->right);
}

void in_order_traverse(struct TreeNode *root)
{
	if (root == NULL) {
		return;
	}
	in_order_traverse(root->left);
	/* 中序遍历 */
	printf("node->val = %d.\n", root->val);
	in_order_traverse(root->right);
}

void post_order_traverse(struct TreeNode *root)
{
	if (root == NULL) {
		return;
	}
	post_order_traverse(root->left);
	post_order_traverse(root->right);
	/* 后序遍历 */
	printf("node->val = %d.\n", root->val);
}
