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

	traverse(root->left);
	printf("%d", root->val);
	traverse(root->right);

}
