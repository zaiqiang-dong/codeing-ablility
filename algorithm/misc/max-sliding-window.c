// https://leetcode-cn.com/problems/sliding-window-maximum/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define QUEMAX    (10000)
typedef struct _Node {
    int i;      // 记录数据的索引
    int value;  // 记录数据的值
}Node;

Node g_que[QUEMAX] = {0};
int g_left = 0;      // 队列的左指针
int g_right = 0;     // 队列的右指针

Node *GetTail() // 获取队尾
{
    int right;
    if (g_left == g_right) {
        return NULL;
    }

    right = (g_right - 1 + QUEMAX) % QUEMAX;
    return &g_que[right];
}

Node *GetHead()  // 获取队头
{
    if (g_left == g_right) {
        return NULL;
    }

    return &g_que[g_left];
}

Node *PopTail()  // 弹出队尾
{
    if (g_left == g_right) {
        return NULL;
    }

    g_right = (g_right - 1 + QUEMAX) % QUEMAX;
    return &g_que[g_right];
}

Node *PopHead() // 弹出队头
{
    int left;
    if (g_left == g_right) {
        return NULL;
    }

    left = g_left;
    g_left = (g_left + 1) % QUEMAX;

    return &g_que[left];
}

void PushTail(int i, int num) // 从队尾入队列
{
    Node *tail;

    tail = GetTail();

    while (tail != NULL && num > tail->value) { // 实现单调递减队列，队头一定是最大值
        PopTail();
        tail = GetTail();
    }

    g_que[g_right].i = i;
    g_que[g_right].value = num;
    g_right = (g_right + 1) % QUEMAX;
}


int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int i;
    Node *node;
    int *r;
    int rn = 0;


    g_left = g_right = 0;
    r = malloc(sizeof(int) * (numsSize - k + 1));

    for (i = 0; i < k; i++) {
        PushTail(i, nums[i]);
    }

    node = GetHead();
    r[rn++] = node->value;

    for (i = k; i < numsSize; i++) {
		/****************************/
		/*保证队列中最多只有K个元素*/
        node = GetHead();
        if (i - k == node->i) {
            PopHead();
        }
		/****************************/
        PushTail(i, nums[i]);  // 继续入队列
        node = GetHead();      // 从队头获取当前队列的最大值
        r[rn++] = node->value;
    }

    *returnSize = rn;
    return r;
}

