#include "binary-tree.h"


struct tree_node * delete_from_bst(struct tree_node *root, int target);
struct tree_node * insert_to_bst(struct tree_node *root, int target);
int is_avild_bst(struct tree_node *root);
int is_in_bst(struct tree_node *root, int target);
int max_sum_bst(struct tree_node *root);
int num_trees(int n);
int find_max(struct tree_node *root);
int find_min(struct tree_node *root);
int find_sum(struct tree_node *root);
