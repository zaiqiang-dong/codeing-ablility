

struct double_link_node{
    int data;
    struct double_link_node *pre;
    struct double_link_node *next;

};


struct double_link_node *
inser_double_link_head(struct double_link_node *head, int data);

struct double_link_node *
inser_double_link_tail(struct double_link_node *head, int data);

struct double_link_node *
inser_double_link_at(struct double_link_node *head, int data, int pos);

struct double_link_node *
del_double_link(struct double_link_node *head, int data);
