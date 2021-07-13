#include "uthash.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct example_user_t {
	int id;
	char name[16];
	UT_hash_handle hh;
} example_user_t;

int main(int argc, char *argv[])
{
	int i;
	example_user_t *user, *users=NULL;

	srand((unsigned int)time(NULL));

	/* create elements */
	for(i=0; i<10; i++) {
		if ( (user = (example_user_t*)malloc(sizeof(example_user_t))) == NULL) exit(-1);

		user->id = rand()%10;
		HASH_ADD_INT(users, id, user);
	}

	for(user=users; user != NULL; user=(example_user_t*)(user->hh.next)) {
		printf("user %d\n", user->id);
	}

	return 0;
}
