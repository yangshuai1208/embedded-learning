#include<stdio.h>
#include<stdbool.h>//使用bool类型明确返回成功失败。
#define MAX 100
typedef struct {
	int data[MAX];
	int front;//队首
	int rear;//队尾
}Queue;
void initQueue(Queue* q) {  //为什么需要初始化队列:将队列置于一致的初始状态（空队列），避免未定义行为。
	q->front = 0;//队首队尾都为0，表示队列为空。
	q->rear = 0;
}
bool isEmpty(Queue*q){
	return q->front == q->rear;//当队首和队尾相等时，表示队列为空。
}
bool isFull(Queue* q) {
	return q->rear == MAX;//当队尾等于MAX时，表示队列已满。
}
//入队操作
bool enqueue(Queue* q, int val) {
	if (isFull(q)) return false;//入队与出队参数区别:是否需要返回值。
	q->data[q->rear++] = val;
	return true;
}
//出队操作
bool dequeue(Queue* q, int *val) {
	if (isEmpty(q)) return false;
	*val = q->data[q->front++];
	return true;
}

int main() {
	Queue q;
	initQueue(&q);
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	int val;
	dequeue(&q, &val);
	printf("dequeue:%d\n", val);
	dequeue(&q, &val);
	printf("dequeue:%d\n", val);
	return 0;
}
//缺点:假溢出：当 rear == MAX 时，即使数组前面有空位（因为 front 前移了），也无法再入队，导致空间浪费。
//队列容量固定为 MAX，不能动态扩展。
