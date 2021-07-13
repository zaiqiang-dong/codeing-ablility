/* 升序遍历 */

#include <stdio.h>


#include "../../include/tree/binary-tree.h"
#include "../../include/tree/binary-serach-tree.h"

void traverse(struct tree_node *root)
{
	if (root == NULL) {
		return;
	}
	// 对每个节点进行的操作

	traverse(root->left);
	printf("%d", root->val);
	traverse(root->right);

}
