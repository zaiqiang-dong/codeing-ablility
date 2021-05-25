struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


void pre_order_traverse(struct TreeNode *root);
void in_order_traverse(struct TreeNode *root);
void post_order_traverse(struct TreeNode *root);

