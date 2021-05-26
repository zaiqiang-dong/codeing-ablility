/**
 * Definition for a binary tree node.
 * struct tree_node {
 *     int val;
 *     struct tree_node *left;
 *     struct tree_node *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>
#include "binary-tree.h"


struct tree_node* construct_maximum_binarytree(int* nums, int numsSize)
{
	int i = 0;
	int idx = 0;
	int max_val = 0;

	if (numsSize <= 0) {
		return NULL;
	}

	for (i = 0; i < numsSize; ++i) {
		if (max_val < nums[i]) {
			idx = i;
			max_val = nums[i];
		}
	}

	struct tree_node *root = (struct tree_node *)malloc(sizeof(struct tree_node));
	root->val = max_val;
	root->left = construct_maximum_binarytree(nums, idx);
	root->right = construct_maximum_binarytree(nums+index+1, numsSize - idx -1);

}

