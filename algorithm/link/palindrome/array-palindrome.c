#include <stdio.h>


int is_palindrome(char *array, int len)
{
	int left = 0;
	int right = len - 1;
	while (left < right) {
		if (array[left] != array[right]) {
			return 0;
		}
		left++;
		right--;
	}
	return 1;
}

int main(int argc, char *argv[])
{
	char test1[] = {'a','c','d','e','d','c','a'};
	char test2[] = {'a','c','d','e','d','c','b'};
	if (is_palindrome(test1, sizeof(test1))) {
		printf("test1 is palindrom.\n");
	} else {
		printf("test1 is not palindrom.\n");
	}
	if (is_palindrome(test2, sizeof(test2))) {
		printf("test2 is palindrom.\n");
	} else {
		printf("test2 is not palindrom.\n");
	}
	return 0;
}
