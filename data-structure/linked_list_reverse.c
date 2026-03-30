#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
}Node;
Node* createNode(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));//动态分配内存，初始化数据域和指针域。
	if (!newNode) return NULL;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void insertAtTail(Node**head,int  data){
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
Node* reverseList(Node* head) {
	Node* prev = NULL;
	Node* curr = head;
	while (curr) {
		Node* next = curr->next;
		curr->next = prev;
		prev = curr;//前驱指针后移。
		curr = next;//当前指针后移。
	}
	return prev;
}
void printList(Node* head) {
	while (head) {
		printf("%d->", head->data);
		head = head->next;
	}
	printf("NULL\n");
}
int main() {
	Node* head = NULL;
	insertAtTail(&head, 1);
	insertAtTail(&head, 2);
	insertAtTail(&head, 3);
	insertAtTail(&head, 4);
	insertAtTail(&head, 5);
	printf("Original:");printList(head);
	head = reverseList(head);
	printf("Reserved");printList(head);

	return 0;
}
