/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

/* https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/ */


struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

void connectTwoNode(struct Node *node1, struct Node *node2)
{
	if (node1 == NULL || node2 = NULL) {
		return;
	}

	node1->next = node2;

	connectTwoNode(node1->left, node1->right);
	connectTwoNode(node2->left, node2->right);
	connectTwoNode(node1->right, node2->left);
}

struct Node* connect(struct Node* root) {
	if (root == NULL) {
		return NULL;
	}

	connectTwoNode(root->left, root->right);

	return root;
}

