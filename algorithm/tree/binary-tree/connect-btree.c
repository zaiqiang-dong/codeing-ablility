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

void connect_twoNode(struct Node *node1, struct Node *node2)
{
	if (node1 == NULL || node2 = NULL) {
		return;
	}

	node1->next = node2;

	connect_twoNode(node1->left, node1->right);
	connect_twoNode(node2->left, node2->right);
	/* 关键节点 */
	connect_twoNode(node1->right, node2->left);
}

struct Node* connect(struct Node* root) {
	if (root == NULL) {
		return NULL;
	}

	connect_twoNode(root->left, root->right);

	return root;
}

