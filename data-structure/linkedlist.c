#include<stdio.h>
#include<stdlib.h>
typedef struct DNode {
	int data;
	struct DNode* prev;//指向前一个节点的指针
	struct DNode* next;//指向后一个节点的指针
}DNode;
DNode* d_create(int data) {
	DNode* new = (DNode*)malloc(sizeof(DNode));//分配内存
	if (!new) return NULL;//分配失败
	new->data = data;
	new->prev= NULL;
	new->next = NULL;
	return new;
}
//头插法
void d_insert_head(DNode** head, int data) {
	DNode* new = d_create(data);
	if (!new) return;//创建节点失败
	if (*head) {
		new->next = *head;
		(*head)->prev = new;//更新原头节点的前指针
	}
	*head = new;//更新头指针
}
//尾插法
void d_insert_tail(DNode** head, int data) {
	DNode*new = d_create(data);
	if (!new) return;
	if(*head== NULL) {
		*head = new;
		return;
	}
	DNode* cur = *head;
	while (cur->next) cur = cur->next;//找到最后一个节点
	cur->next = new;//更新最后一个节点的后指针
	new->prev = cur;//更新新节点的前指针
}
//删除节点
void d_delete(DNode** head, int data) {
	if (!*head) return;//链表为空
	DNode* cur = *head;
	while (cur && cur->data != data) cur = cur->next;//找到要删除的节点
	if (!cur) return;//未找到节点
	if (cur->prev) cur->prev->next = cur->next;//更新前一个节点的后指针
	else *head = cur->next;//如果删除的是头节点，更新头指针
	if (cur->next) cur->next->prev = cur->prev;//更新后一个节点的前指针
	free(cur);//释放内存
}
//正向遍历打印链表
void d_print_forward(DNode* head) {
	while (head) {
		printf("%d<->", head->data);
		head = head->next;
	}
	printf("NULL\n");
}
//释放整个链表
void d_free(DNode** head) {
	DNode* cur = *head;//接收头指针
	while (cur) {
		DNode* tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	*head = NULL;//重置头指针
}
int main() {
	printf("=====双向链表====\n");
	DNode* dhead = NULL;
	d_insert_tail(&dhead, 10);
	d_insert_tail(&dhead, 20);
	d_insert_tail(&dhead, 50);
	d_print_forward(dhead);
	 
	d_delete(&dhead, 100);
	d_print_forward(dhead);//删除不存在的节点，链表不变
	d_free(&dhead);//释放链表内存
	
	return 0;
}
