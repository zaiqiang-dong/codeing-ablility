#include "hash.h"
#include <malloc.h>
#include <stdlib.h>


struct test_data{
	int value;
	char key[64];
	int key_int;
};

static void free_test_data(void *data)
{
	free(data);
}

int main(int argc, char *argv[])
{
	struct hash_table *ht = hash_table_create();
	struct test_data *tmp;
	int i = 0;
	char key_tmp[64];

/*
 *    for (i = 0; i < 100; i++) {
 *        tmp = (struct test_data *)malloc(sizeof(struct test_data));
 *        tmp->value = rand() % 100;
 *        sprintf(tmp->key, "data-%d", i);
 *        tmp->key_int = i;
 *        hash_table_add_kv(ht, tmp->key, tmp, free_test_data);
 *    }
 *
 *    for (i = 0; i < 100; i++) {
 *        sprintf(key_tmp, "data-%d", i);
 *        tmp = hash_table_get_kv(ht, key_tmp);
 *        printf("%s value = %d\n", key_tmp, tmp->value);
 *    }
 */

	for (i = 0; i < 100; i++) {
		tmp = (struct test_data *)malloc(sizeof(struct test_data));
		tmp->value = rand() % 100;
		tmp->key_int = i;
		hash_table_add_kv(ht, (char *)&tmp->key_int, tmp, free_test_data);
	}

	for (i = 0; i < 100; i++) {
		tmp = hash_table_get_kv(ht, (char *)&i);
		printf("%d value = %d\n", i, tmp->value);
	}

	hash_table_remove(ht);

	return 0;
}
