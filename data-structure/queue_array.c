#include<stdio.h>
#include<stdbool.h>//使用bool类型明确返回成功失败。
#define MAX 100
typedef struct {
	int data[MAX];
	int front;//队首
	int rear;//队尾
}Queue;
void initQueue(Queue* q) {
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
	if (isFull(q)) return false;
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
