#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static int test_val = 0;

int main(){
	int child_thread = 0;
	int exit_state = 0;

	printf("this father and pid = %d.\n", getpid());
	child_thread = fork();

	if (child_thread < 0) {
		printf("create child thread faild.\n");
	} else if (child_thread == 0) {
		test_val++;
		sleep(3);
		printf("this is child thread and test_val = %d.\n", test_val);
		exit(0);
	} else {
		printf("this is father thread.\n");
	}
	//wait(&exit_state);
	printf("test_val = %d, end.\n", test_val);
}
