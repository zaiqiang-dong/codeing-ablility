#include <stdio.h>
#include <stdlib.h>

#include "binary-tree.h"


static int *buff;

void serialize_func(struct tree_node *root)
{
	if (root == NULL) {
		*buff = '#';
		buff++;
		return;
	}

	*buff = root->val;
	buff++;
	serialize_func(root->left);
	serialize_func(root->right);
}

struct tree_node * reserialize_func()
{
	struct tree_node *root = NULL;
	if (*buff == '\0') {
		return NULL;
	}

	if (*buff == '#') {
		buff++;
		return NULL;
	}

	root = (struct tree_node *)malloc(sizeof(struct tree_node));
	root->val = *buff;
	buff++;
	root->left = reserialize_func();
	root->right = reserialize_func();
	return root;

}

void serialize(struct tree_node *root, int *array)
{
	buff = array;
	serialize_func(root);

}
struct tree_node * reserialize(int *array)
{
	buff = array;
	return reserialize_func();

}

