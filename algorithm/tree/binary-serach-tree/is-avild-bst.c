#include <stdio.h>
#include "../datastruct/binary-tree.h"


/* 前序 */
int check(struct tree_node *root, struct tree_node *min, struct tree_node *max)
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

int is_avild_bst(struct tree_node *root)
{
	return check(roo, NULL, NULL);
}

