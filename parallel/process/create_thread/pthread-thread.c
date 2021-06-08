#include "stdio.h"
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>

pid_t gettid(void){
    return syscall(SYS_gettid);
}

static int test_val = 0;

void *grandson_function(void *arg){
	test_val++;
	printf("grandson thread and test_val = %d. pid=%d\n", test_val, gettid());
	sleep(20);
}

void *son_function(void *arg){
	test_val++;
	pthread_t tid;
	printf("son thread and test_val = %d. pid=%d\n", test_val, gettid());
	pthread_create(&tid, NULL, grandson_function, NULL);
	pthread_join(tid, NULL);
	sleep(5);
}

int main(){
	pthread_t tid;

	printf("this father thread and test_val = %d.  pid=%d\n", test_val, gettid());
	pthread_create(&tid, NULL, son_function, NULL);
	pthread_join(tid, NULL);


	return 0;
}
