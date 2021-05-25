/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>
#include "binary-tree.h"


struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
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

	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = max_val;
	root->left = constructMaximumBinaryTree(nums, idx);
	root->right = constructMaximumBinaryTree(nums+index+1, numsSize - idx -1);

}

