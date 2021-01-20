/*
 * single link
 * author : Zaiqiang Dong
 */

struct single_link_node{
   int val;
   struct single_link_node *next;
};

struct single_link{
    int len;
    struct single_link_node *head;
    struct single_link_node *tail;
};

struct single_link * create_single_link();
struct single_link_node * create_single_link_node();
void single_link_insert_head(struct single_link *link, int val);
void single_link_insert_tail(struct single_link *link, int val);
int single_link_find(struct single_link *link, int val);
void single_link_delete_node(struct single_link *link, int val);
int single_link_size(struct single_link *link);
int single_link_is_empty(struct single_link *link);
void single_link_destory(struct single_link *link);
