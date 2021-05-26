
/* traverse  model */


void traverse(struct tree_node *root)
{
	/* 前序遍历 */
	traverse(root.left);
	/* 中序遍历 */
	traverse(root.right);
	/* 后序遍历 */
}
