
/* 将以root为根的树挂拉平成链表 */
/* https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/ */


/**
 * Definition for a binary tree node.
 * struct tree_node {
 *     int val;
 *     struct tree_node *left;
 *     struct tree_node *right;
 * };
 */

#include "binary-tree.h"

void flatten(struct tree_node *root){
	if (root == NULL) {
		return;
	}

	/* last */
	flatten(root->left);
	flatten(root->right);

	struct tree_node *left = root->left;
	struct tree_node *right = root->right;

	/* 设置root left 为 null */
	root->left = NULL;
	root->right = left;

	struct tree_node *p = root;
	while (p->right != NULL) {
		p = p->right;
	}

	p->right = right;
}
