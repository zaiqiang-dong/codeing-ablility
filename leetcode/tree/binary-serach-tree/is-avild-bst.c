#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}

/* 前序 */
int check(struct TreeNode *root, struct TreeNode *min, struct TreeNode *max)
{
	int rl = 0;
	int rr = 0;
	if (root == NULL) {
		return 1;
	}

	if (min != NULL && root->val <= min->val) {
		return 0;
	}
	if (max != NULL && root->val >= max->val) {
		return 0;
	}

	rl = check(root->left, min, root);
	rr = check(root->right, root, max);

	if (rl == 1 && rr == 1) {
		return 1;
	} else {
		return 0;
	}
}

int is_avild_bst(struct TreeNode *root)
{
	return check(roo, NULL, NULL);
}

