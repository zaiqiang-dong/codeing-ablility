#define TABLE_SIZE (1024*1024)

struct kv{
    struct kv *next;
    char *key;
    void *value;
    void(*free_value)(void*);
};


struct hash_table{
    struct kv **table;
};

struct hash_table * hash_table_create();
void hash_table_remove(struct hash_table *ht);

int hash_table_add_kv(struct hash_table *ht, char *key, void *value,
                            void(*free_value)(void*));
void *hash_table_get_kv(struct hash_table *ht, char *key);
void hash_table_del_kv(struct hash_table *ht, char *key);
