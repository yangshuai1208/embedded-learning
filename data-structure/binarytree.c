#include<stdio.h>
#include<stdlib.h>
//二叉树节点结构体
typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;
//队列节点和队列结构体（用于层级遍历）
typedef struct QueueNode {
	TreeNode* treeNode;
	struct QueueNode* next;
}QueueNode;
typedef struct {
	QueueNode* front;
	QueueNode* rear;
}Queue;
//创建二叉树节点
TreeNode* createNode(int data) {
	TreeNode* new = (TreeNode*)malloc(sizeof(TreeNode));
	if (!new) return NULL;
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}
//递归遍历1.前序遍历（根左右）
void preorder(TreeNode* root) {
	if (!root) return;
	printf("%d", root->data);
	preorder(root->left);
	preorder(root->right);
}
//中序遍历（左根右）
void inorder(TreeNode* root) {
	if (!root) return;
	inorder(root->left);
	printf("%d", root->data);
	inorder(root->right);
}
//后序遍历（左右根）
void postorder(TreeNode* root) {
	if (!root) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d", root->data);
}
//队列操作函数
void initQueue(Queue* q) {
	q->front = q->rear = NULL;//队首队尾都设为NULL表示队列为空。
}
//入队操作：创建一个新的队列节点，将其加入到队尾。
void enqueue(Queue* q, TreeNode* node) {
	QueueNode* new = (QueueNode*)malloc(sizeof(QueueNode));
	if (!new) return;
	new->treeNode = node;
	new->next = NULL;
	if(q->rear==NULL){
		q->front = q->rear = new;
	}
	else {
		q->rear->next = new;
		q->rear = new;
	}
}
//出队操作：从队首移除一个节点，并返回其对应的二叉树节点。
TreeNode* dequeue(Queue* q) {
	if (q->front == NULL) return NULL;
	QueueNode* temp = q->front;
	TreeNode* node = temp->treeNode;
	q->front = q->front->next;
	if (q->front == NULL) q->rear = NULL;
	free(temp);
	return node;
}
//检查队列是否为空：如果队首为NULL，说明队列为空。
int isQueueEmpty(Queue* q) {
	return q->front == NULL;
}
//层级遍历：使用队列实现，从根节点开始，依次访问每一层的节点，并将其子节点加入队列。
void levelOrder(TreeNode* root) {
	if (!root) return;
	Queue q;
	initQueue(&q);
	enqueue(&q, root);
	while (!isQueueEmpty(&q)) {
		TreeNode* current = dequeue(&q);
		printf("%d", current->data);
		if (current->left) enqueue(&q, current->left);
		if (current->right) enqueue(&q, current->right);
	}
}
TreeNode *buildSampleTree() {
	TreeNode* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	return root;
}
int main() {
	TreeNode* root = buildSampleTree();
	printf("前序遍历:"); preorder(root);printf("\n");
	printf("中序遍历:" );inorder(root);printf("\n");
	printf("后序遍历:"); postorder(root);printf("\n");
	printf("层级遍历:"); levelOrder(root); printf("\n");
	return 0;
}
