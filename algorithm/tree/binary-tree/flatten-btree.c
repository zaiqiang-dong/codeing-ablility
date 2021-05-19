
/* 将以root为根的树挂拉平成链表 */
/* https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/ */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

void flatten(struct TreeNode *root){
	if (root == NULL) {
		return;
	}

	/* last */
	flatten(root->left);
	flatten(root->right);

	struct TreeNode *left = root->left;
	struct TreeNode *right = root->right;

	/* 设置root left 为 null */
	root->left = NULL;
	root->right = left;

	struct TreeNode *p = root;
	while (p->right != NULL) {
		p = p->right;
	}

	p->right = right;
}
