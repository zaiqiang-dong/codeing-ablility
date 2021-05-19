/* 升序遍历 */

#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}

void traverse(struct TreeNode *root)
{
	if (root == NULL) {
		return;
	}
	// 对每个节点进行的操作

	traverse(root->left);
	printf("%d", root->val);
	traverse(root->right);

}
