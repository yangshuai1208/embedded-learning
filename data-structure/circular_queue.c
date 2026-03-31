#include<stdio.h>
#include<stdbool.h>
#define MAX 5
typedef struct {
	int data[MAX];
	int front;
	int rear;
}CircularQueue;
//初始化队列
void initQueue(CircularQueue *q){
	q->front = 0;//队头指向第一个元素
	q->rear = 0;
}
//判断队列是否为空
bool isEmpty(CircularQueue*q){
	return q->front == q->rear;
}
//判断队列是否满
bool isFull(CircularQueue* q) {
	return (q->rear + 1) % MAX == q->front;//当rear指向下一个位置时，如果这个位置是front，则说明队列满了
}
//入队
bool enqueue(CircularQueue* q, int val) {
	if(isFull(q)) return false;
	q->data[q->rear] = val;//将元素放在rear指向的位置
		q->rear=(q->rear+1)%MAX;
		return true;
}
//出队
bool dequeue(CircularQueue* q, int* val) {
	if(isEmpty(q)) return false;
	*val=q->data[q->front];
	return true;
}
int main() {
	CircularQueue q;
	initQueue(&q);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	int val;
	dequeue(&q, &val);
	printf("dequeue:%d\n", val);
	while (!isEmpty(&q)) {
		dequeue(&q, &val);
		printf("%d,", val);
	}
	return 0;
}
