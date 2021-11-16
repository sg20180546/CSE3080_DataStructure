#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef struct node{
	char data;
	struct node* left;
	struct node* right;
}Node;

Node* root;


void initTree(int data){
	Node* New;
	New=(Node*)malloc(sizeof(Node));
	root=New;
	root->data=data;
	New->left=NULL;
	New->right=NULL;
}

Node* AddChild(Node* parent, int data){
 	if(parent->left!=NULL&&parent->right!=NULL){
 		printf("its already full, cannot add \n");
 		return 0;
	 }
	 Node *New;
	 New=(Node*)malloc(sizeof(Node));
	 New->left=NULL;
	 New->right=NULL;
	 New->data=data;
	 if(parent->left==NULL) parent->left=New;
	 else if(parent->right==NULL) parent->right=New;
	 
	 return New;
 }
// 전위순회 preorder 
 void PreOrder(Node *r){
 	printf("%c ",r->data);
 	if(r->left) PreOrder(r->left);
 	if(r->right) PreOrder(r->right);
 }
 
 void PostOrder(Node* r){
 	if(r->left) PostOrder(r->left);
 	if(r->right) PostOrder(r->right);
 	printf("%c ",r->data);
 }
 
void InOrder(Node* r){
	if(r->left) InOrder(r->left);
	printf("%c ",r->data);
	if(r->right) InOrder(r->right);
} 
// level order 
Node* Queue[MAX_QUEUE_SIZE];
int front=0;
int rear=0;

void Enqueue(Node* ptr){
	Queue[++rear]=ptr;
}
Node* Dequeue(){
	return Queue[++front];
}


void LevelOrder(Node* r){
	if(!r) return;
	Enqueue(r);
	
	while(1){
		r=Dequeue();
		if(r){
			printf("%c ", r->data);
			if(r->left) Enqueue(r->left);
			if(r->right) Enqueue(r->right);
		}else break;
	}	
}
 
 int main(void){
 	initTree('A');
 	Node *l=AddChild(root,'B');
 	Node *r=AddChild(root,'C');
 	AddChild(l,'D');
 	AddChild(l,'E');
 	AddChild(r,'F');
 	AddChild(r,'G');
// 	PreOrder(root);
//	PostOrder(root);
	InOrder(root);
//	LevelOrder(root);
 	
 	return 0;
 }
