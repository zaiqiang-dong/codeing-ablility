/*
 * https://leetcode-cn.com/problems/maximum-sum-bst-in-binary-tree/
 *
 */


#include <stdio.h>
#include <stdlib.h>

#include "../datastruct/binary-tree.h"

static int max_sum = 0;

static int find_max(struct TreeNode *root);
static int find_min(struct TreeNode *root);
static int find_sum(struct TreeNode *root);
static int is_bst(struct TreeNode *root);

#define MAX_INT ((unsigned int)(-1 >> 1))
#define MIN_INT (~MAX_INT)

/* 主函数 */

int max_sum_bst(struct TreeNode *root)
{
	traverse(root);
	return max_sum;

}


/* 方法一:前序 */
void traverse(struct TreeNode *root)
{
	int left_max,right_min;
	int left_sum,right_sum;
	int root_sum;

	if (root == NULL) {
		return;
	}

	if ( !is_bst(root->left) || !is_bst(root->right)) {
		goto next;
	}

	left_max = find_max(root->left);
	right_min = find_min(root->right);

	if (root->val <= left_max || root->val >= right_max) {
		goto next;
	}

	left_sum = find_sum(root->left);
	right_sum = find_sum(root->right);

	/* 计算新的sum */
	root_sum = left_max + right_max + root->val;

	/* 更新 max_sum */
	max_sum = root_sum > max_sum ? root_sum : max_sum;


next:
	traverse(root->left);
	traverse(root->right);
}

/* 方法二:后序 */
/*
 * traverse(root) 返回一个大小为 4 的 int 数组，我们暂且称它为 res，其中：
 * res[0] 记录以 root 为根的二叉树是否是 BST，若为 1 则说明是 BST，若为 0 则说明不是 BST；
 * res[1] 记录以 root 为根的二叉树所有节点中的最小值；
 * res[2] 记录以 root 为根的二叉树所有节点中的最大值；
 * res[3] 记录以 root 为根的二叉树所有节点值之和。
 *
 */
int * traverse(struct TreeNode *root)
{
	int *res;
	int *left,*right;

	res = (int *)malloc(sizeof(int)*4);
	if (root == NULL) {
		res[0] = 1;
		res[1] = MAX_INT;
		res[2] = MIN_INT;
		res[3] = 0;
		return ;
	}

	/* 递归计算左右子树 */
	left = traverse(root->left);
	right = traverse(root->right);

	if (left[0] == 1 && right[0] == 1
			root->val > left[2] && root->val < right[1]) {
		res[0] = 1;
		res[1] = left[1] < root->val ? left[1] : root->val;
		res[2] = right[2] > root->val ? right[1] : root->val;
		res[3] = left[3] + right[3] + root->val;

		max_sum = max_sum > res[3] ? max_sum : res[3];

	} else {
		res[0] = 0;
	}

	return res;
}
