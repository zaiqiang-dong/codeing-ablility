/*
 * https://leetcode-cn.com/problems/unique-binary-search-trees/
 */

#include <stdio.h>

int memo[3][3];

int count(int lo, int hi)
{
	int i, ret;
	int left,right;
	if (lo > hi) {
		return 1;
	}
	if (memo[lo][hi] != 0) {
		return memo[lo][hi];
	}
	ret = 0;
	for (i = lo; i <= hi; i++) {
		left = count(lo, i-1);
		right = count(i+1, hi);
		ret += left * right;
	}

	memo[lo][hi] = ret;
	return ret;

}

int num_trees(int n)
{
	count(1, n);
}


int main(int argc, char *argv[])
{
	printf("n = 3, numTrees = %d.\n", num_trees(3));
	return 0;
}
