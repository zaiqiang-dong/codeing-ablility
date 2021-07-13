struct tree_node {
	int val;
	struct tree_node *left;
	struct tree_node *right;
};


void pre_order_traverse(struct tree_node *root);
void in_order_traverse(struct tree_node *root);
void post_order_traverse(struct tree_node *root);

/* 镜像翻转 */
struct tree_node * invertTree(struct tree_node *root);
struct tree_node* constructMaximumBinaryTree(int* nums, int numsSize);
struct tree_node * reserialize(int *buff);
void serialize(struct tree_node *root, int *buff);
