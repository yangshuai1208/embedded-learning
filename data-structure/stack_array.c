#include<stdio.h>
#include<stdbool.h>
#define MAX 100
typedef struct {
	int data[MAX];//固定大小的整型数组，用于存储栈元素。
	int top;//栈顶
}Stack;
//初始化
void initStack(Stack* s) {
	s->top = -1;//初始化栈顶指针为-1，表示栈为空。
}
//判断栈空
bool isEmpty(Stack* s) {
	return s->top == -1;//判断栈是否为空，如果栈顶指针为-1，则返回true，否则返回false。
}
//判满
bool isFull(Stack* s) {
	return s->top == MAX - 1;//当top达到MAX-1时，数组已满，无法继续压栈。
}
//压栈
bool push(Stack* s, int val) {
	if (isFull(s)) return false;//如果栈已满，无法压栈，返回false。
	s->data[++(s->top)] = val;
	return true;//将元素压入栈中，并返回true表示成功。
}
//出栈
bool pop(Stack* s, int* val) {
	if (isEmpty(s)) return false;
	*val = s->data[(s->top)--];//先取出栈顶元素，再减，移动栈顶指针，将取出的元素通过指针 val 返回给调用者。
	return true;
}
//取栈顶元素
bool peek(Stack* s, int*val){
	if (isEmpty(s)) return false;
	*val = s->data[s->top];//只读取，不移动。
	return true;
}
int main() {
	Stack s;
	initStack(&s);
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	int val;
	pop(&s, &val);
	printf("pop:%d\n", val);
	peek(&s, &val);
	printf("top:%d\n", val);
	return 0;
}
