struct tree_node {
	int val;
	struct tree_node *left;
	struct tree_node *right;
};


void pre_order_traverse(struct tree_node *root);
void in_order_traverse(struct tree_node *root);
void post_order_traverse(struct tree_node *root);

