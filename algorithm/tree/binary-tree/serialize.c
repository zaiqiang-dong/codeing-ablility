#include <stdio.h>
#include <stdlib.h>

#include "binary-tree.h"

#define ARRAY_SIZE 100

static int sbuff[ARRAY_SIZE] = {'\0'};
static int *buff;

void serialize(struct TreeNode *root)
{
	if (root == NULL) {
		*buff = '#';
		buff++;
		return;
	}

	*buff = root->val;
	buff++;
	serialize(root->left);
	serialize(root->right);
}

struct TreeNode * reserialize()
{
	struct TreeNode *root = NULL;
	if (*buff == '\0') {
		return NULL;
	}

	if (*buff == '#') {
		buff++;
		return NULL;
	}

	root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = *buff;
	buff++;
	root->left = reserialize(buff);
	root->right = reserialize(buff);
	return root;

}


int main(int argc, char *argv[])
{

	struct TreeNode *root = NULL;
	sbuff[0] = 1;
	sbuff[1] = 2;
	sbuff[2] = '#';
	sbuff[3] = 4;
	sbuff[4] = '#';
	sbuff[5] = '#';
	sbuff[6] = 3;
	sbuff[7] = '#';
	sbuff[8] = '#';

	buff = sbuff;
	root = reserialize();
	pre_order_traverse(root);

	buff = sbuff;
	serialize(root);

	return 0;
}
