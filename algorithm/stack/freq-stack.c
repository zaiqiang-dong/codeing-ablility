//https://leetcode-cn.com/problems/maximum-frequency-stack/


/*************************************************************************/
typedef struct {
	int* top;
	int* button;
	int* freqNum;
	int maxIndex;
	int len;
} FreqStack;

FreqStack* freqStackCreate()
{
	FreqStack *FS = (FreqStack *)malloc(sizeof(FreqStack));
	FS->button = (int *)malloc(4*10000);
	memset(FS->button, 0, 4*10000);
	FS->freqNum = (int *)malloc(4*10000);
	memset(FS->freqNum, 0, 4*10000);
	FS->top = FS->button;
	FS->maxIndex = 0;
	FS->len = 0;
	return FS;
}

void freqStackPush(FreqStack* obj, int x)
{
	if (obj->len > 0) {
		obj->top++;
	}

	*obj->top = x;
	obj->len++;

	if (obj->len ==1) {
		obj->freqNum[0] = 1;
		obj->maxIndex =0;
		//printf("PUSH maxIndex: %d\n", obj->maxIndex);
		return;
	}

	obj->freqNum[obj->len - 1] = 1;
	int len = obj->len;

	for (int i = len - 2; i >= 0; i--) {
		if (*(obj->button + i) == x) {
			obj->freqNum[len - 1] = obj->freqNum[i] + 1;
			//printf("freqNum[len - 1]: %d ", obj->freqNum[len - 1]);
			break;
		}
	}

	if (obj->freqNum[len - 1] >= obj->freqNum[obj->maxIndex])
		obj->maxIndex = len - 1;

	//printf("PUSH maxIndex: %d\n", obj->maxIndex);
}

int freqStackPop(FreqStack* obj)
{
	if (obj->len == 1) {
		obj->len = 0;
		return *obj->button;
	}

	int oldMaxFrqNum = obj->freqNum[obj->maxIndex];
	int num = 0;
	int maxNum = obj->button[obj->maxIndex];

	//printf("maxNum: %d\n", maxNum);
	int *tmp = obj->button + obj->maxIndex;
	int *idxTmp = obj->freqNum + obj->maxIndex;

	//printf("maxIndex: %d, maxNum: %d\n", maxIndex, maxNum);
	if (tmp == obj->top) {
		obj->top--;
		obj->freqNum[obj->len-1] = 0;
		obj->len--;
	} else {
		memmove(tmp, tmp + 1, 4*(obj->len - obj->maxIndex -1));
		memmove(idxTmp, idxTmp + 1, 4*(obj->len - obj->maxIndex -1));
		obj->top--;
		obj->len--;
	}

	int len = obj->len - 1;

	for(int j = len; j >= 0; j--) {
		if (obj->freqNum[j] > num) {
			obj->maxIndex = j;
			num = obj->freqNum[j];

			if (num == oldMaxFrqNum)
				break;
		}
	}

	//printf("POP maxIndex: %d\n", obj->maxIndex);
	return maxNum;
}

void freqStackFree(FreqStack* obj)
{
	free(obj->button);
	free(obj->freqNum);
	obj->button = NULL;
	obj->top = NULL;
	obj->len = 0;
}

/**
 * Your FreqStack struct will be instantiated and called as such:
 * FreqStack* obj = freqStackCreate();
 * freqStackPush(obj, x);
 * int param_2 = freqStackPop(obj);
 * freqStackFree(obj);
*/

/*************************************************************************/
typedef struct num {
	int val;  /* 数字值 */
	int freq; /* 出现次数 */
	struct num *next;
} Num;

typedef struct {
	Num head;  /* 链表头，最终的栈顶就在链表头 */
} FreqStack;

typedef struct myStruct {
	int val;
	int cnt;
	UT_hash_handle hh;
} Node;

Node *map;  /* hash表，保存出现次数 */
Num *tail;  /* 链表尾部，其实也可以不用设置，直接用curr的pre来操作也可以 */
FreqStack* freqStackCreate()
{
	map = NULL;
	FreqStack *root = calloc(1, sizeof(FreqStack));
	tail = &root->head;
	return root;
}

void freqStackPush(FreqStack* obj, int x)
{
	Node *s = NULL;
	HASH_FIND_INT(map, &x, s); /* 查找当前x之前出现几次，如果有就+1，没有就创建，并赋值出现次数为1 */

	if (s == NULL) {
		s = calloc(1, sizeof(Node));
		s->val = x;
		s->cnt++;
		HASH_ADD_INT(map, val, s);
	} else {
		s->cnt++;
	}

	Num *node = calloc(1, sizeof(Num));
	node->val = x;
	node->freq = s->cnt;
	Num *curr = obj->head.next;
	Num *pre = &obj->head;

	while (curr != NULL) {  /* 在链表中做插入排序，排序关键字就是出现次数freq，找到第1个不大于当前x的，插入此位置 */
		if (node->freq < curr->freq) {
			pre = curr;
			curr = curr->next;
		} else {
			node->next = curr;
			pre->next = node;
			break;
		}
	}

	if (curr == NULL) {
		tail->next = node;
		tail = tail->next;
	}
}
int freqStackPop(FreqStack* obj)
{
	int res;
	Num *pop = obj->head.next;  /* 当前链表头的一定是出现次数最多且之前最后出现的，就是结果 */

	if (pop != NULL) {
		res = pop->val;
	}

	Node *s = NULL;
	HASH_FIND_INT(map, &res, s);  /* 调整hash表中此项的值 */

	if (s->cnt == 1) {
		HASH_DEL(map, s);
		free(s);
	} else {
		s->cnt--;
	}

	obj->head.next = pop->next;
	free(pop);
	return res;
}
void freqStackFree(FreqStack* obj)  /* 释放整个链表，释放hash表 */
{
	Num *del, *pre;
	del = obj->head.next;
	pre = &obj->head;

	while (del != NULL) {
		pre->next = del->next;
		free(del);
		del = pre->next;
	}

	tail = NULL;
	free(obj);
	Node *s, *tmp;
	HASH_ITER(hh, map, s, tmp) {
		HASH_DEL(map, s);
		free(s);
	}
}

