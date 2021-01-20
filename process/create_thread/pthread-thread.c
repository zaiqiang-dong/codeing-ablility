#include "stdio.h"
#include <pthread.h>
#include <unistd.h>

static int test_val = 0;

void *pthread_function(void *arg){
	test_val++;
	sleep(3);
	printf("child thread and test_val = %d.\n", test_val);
}

int main(){
	pthread_t tid;

	pthread_create(&tid, NULL, pthread_function, NULL);
	pthread_join(tid, NULL);

	printf("this father thread and test_val = %d.\n", test_val);

	return 0;
}
