#include <malloc.h>
#include <string.h>
#include "hash.h"


static unsigned int hash_33(char *key)
{
	unsigned int hash = 0;
	while (*key) {
		hash = (hash << 5) + hash + *key++;
	}
	return hash % TABLE_SIZE;
}

static void free_kv(struct kv *p)
{
	p->free_value(p->value);
	free(p->key);
	free(p);
}


void hash_table_remove(struct hash_table *ht)
{
	int i = 0;
	struct kv * p;
	struct kv * tmp;
	if (ht) {
		for (i = 0; i < TABLE_SIZE; i++) {
			p = ht->table[i];
			while (p) {
				tmp = p->next;
				free_kv(p);
				p = tmp;

			}
		}
		free(ht->table);
		free(ht);
	}
}

struct hash_table * hash_table_create()
{
	struct hash_table *ht =
		(struct hash_table *)malloc(sizeof(struct hash_table));

	if (ht == NULL) {
		return NULL;
	}

	ht->table = (struct kv **)malloc(sizeof(struct kv *) * TABLE_SIZE);
	if (!ht->table) {
		hash_table_remove(ht);
		return NULL;
	}

	memset(ht->table, 0, sizeof(struct kv *) * TABLE_SIZE);

	return ht;
}

int hash_table_add_kv(struct hash_table *ht, char *key, void *value,
                            void(*free_value)(void*))
{
	unsigned int idx = hash_33(key);
	struct kv *p = ht->table[idx];
	struct kv *h = p;

	struct kv *new = NULL;
	char *new_key = NULL;

	if (p) {
		while (p) {
			if (strcmp(p->key, key) == 0) {
				p->free_value(p->value);
			}
			p->value = value;
			p->free_value = free_value;
			return 1;
		}
	}

	if (!p) {
		new = (struct kv *) malloc(sizeof(struct kv));
		if(!new)
			return 0;

		new_key = (char *)malloc(strlen(key)+1);
		if (!new_key) {
			return 0;
		}

		new->next = NULL;
		strcpy(new_key, key);
		new->key = new_key;
		new->value = value;
		new->free_value = free_value;

		if (h) {
			new->next = h->next;
			h->next = new;
		} else {
			ht->table[idx] = new;
		}

	}

	return 1;

}

void *hash_table_get_kv(struct hash_table *ht, char *key)
{
	unsigned int idx = hash_33(key);
	struct kv *p = ht->table[idx];

	while (p) {
		if (strcmp(p->key, key) == 0) {
			return p->value;
		}
		p = p->next;
	}
	return NULL;
}

void hash_table_del_kv(struct hash_table *ht, char *key)
{
	unsigned int idx = hash_33(key);
	struct kv *p = ht->table[idx];
	struct kv *pre = p;

	while (p) {
		if (strcmp(p->key, key) == 0) {
			if (p == pre) {
				ht->table[idx] = NULL;
			} else {
				pre->next = p->next;
			}
			free_kv(p);
			return;
		}

		p = p->next;
		pre = p;
	}
}
