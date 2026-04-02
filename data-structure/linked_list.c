#include<stdio.h>//提供printf等输入输出函数。
#include<stdlib.h>//提供malloc动态内存分配函数

//结构体定义与类型别名
typedef struct Node {
	int data;
	struct Node* next;
}Node;//定义了一个链表节点结构体。
//节点创建函数，链表节点是在堆上创建的，需要通过指针来访问它。
Node* createNode(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}//动态分配一个节点内存，并检查分配是否成功。
//头插法，Node**head是因为需要修改外部的头指针。
void insertAtHead(Node** head, int data) {
	Node* newNode = createNode(data);
	if (!newNode) return;
	newNode->next = *head;
	*head = newNode;
}//next指向当前头节点，然后更新头指针为新节点。
//尾插法
void insertAtTail(Node** head, int data) {
	Node* newNode = createNode(data);
	if (!newNode) return;
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while (temp->next) temp = temp->next;
	temp->next = newNode;
}
//打印链表
void printList(Node* head) {
	while (head) {
		printf("%d->", head->data);
		head = head->next;
	}
	printf("NULL\n");
}
int main()
{
	Node* head = NULL;
	insertAtHead(&head, 10);//头插：10->NULL;
	insertAtHead(&head, 20);//头插:20->10->NULL;
	insertAtTail(&head, 30);//尾插:20->10->30->NULL;
	insertAtTail(&head, 40);//尾插:20->10->30->40->NULL;
	printList(head);
	return 0;
}
