#define _GNU_SOURCE
#include <stdio.h>
#include <malloc.h>
#include <unistd.h>

#include <sched.h>

#define CHILD_STACK_SIZE 8192
static int test_val = 0;


int child_func(){
	test_val++;
	sleep(3);
	printf("this child and test_val = %d.\n", test_val);
	return 0;
}

int main(){
	void *stack = malloc(CHILD_STACK_SIZE);
	int flags = CLONE_VFORK | CLONE_VM;
	clone(&child_func, (char *)stack + CHILD_STACK_SIZE, flags, 0);

	printf("this is father thread and test_val = %d.\n", test_val);
	return 0;
}
