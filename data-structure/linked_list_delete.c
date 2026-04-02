#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;//自引用结构体。
}Node;
Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));//动态分配内存，创建一个新的节点。
	if (!newNode) return NULL;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//尾插法
void insertAtTail(Node** head, int data) { //Node** head 二级指针，因为函数可能需要修改头指针（当链表为空时，头指针会指向新节点）。
	Node* newNode = createNode(data);
	if (!newNode) return;
	if (*head == NULL) {//如果链表为空，直接将新节点作为头节点。
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while (temp->next) temp = temp->next;
	temp->next = newNode;
}
void deleteNode(Node** head, int value) {
	if (*head == NULL) return;//如果链表为空，直接返回。
	Node* temp = *head;
	if (temp->data == value) {
		*head = temp->next;//如果头节点就是要删除的节点，直接将头指针指向下一个节点。
		free(temp);//释放内存，删除节点。
		return;
	}
	Node* prev = NULL;
	while (temp && temp->data != value) {
		prev = temp;//使用prev记录前驱，找到目标节点后，将前驱的next指向目标节点的next，再释放目标节点。
		temp = temp->next;
	}
	if (!temp) return;//如果没有找到要删除的节点，直接返回。
	prev->next = temp->next;//将前一个节点的next指针指向要删除节点的下一个节点。
	free(temp);//释放内存，删除节点。
}
void freeList(Node** head)
{
	Node* temp = *head;
	while(temp){
		Node* next = temp->next;//保存下一个节点的地址，因为释放当前节点后，无法再访问它的next指针。
		free(temp);//释放整个链表是负责任的内存管理。
		temp = next;//释放当前节点后，继续释放下一个节点。
	}
	*head = NULL;//防止悬空指针。
}
void printList(Node* head) {
	while (head) {
		printf("%d->", head->data);
		head=head->next;
	}
	printf("NULL\n");
}
int main()
{
	Node* head = NULL;
	insertAtTail(&head, 1);
	insertAtTail(&head, 2);
	insertAtTail(&head, 3);
	printf("Original");printList(head);
	deleteNode(&head, 2);
	printf("After deleting 2");printList(head);
	deleteNode(&head, 1);
	printf("After deleting 1");printList(head);
	deleteNode(&head, 100);
	printf("After deleting 100");printList(head);
	freeList(&head);
	return 0;
}
