/* 把一个二叉树进行镜像翻转 */

#include "binary-tree.h"

struct tree_node * invert_tree(struct tree_node *root)
{
	/* 前序的位置进行交换 */

	struct tree_node *tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	invert_tree(root->left);
	invert_tree(root->right);

	return root;
}

