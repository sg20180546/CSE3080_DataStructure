#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int key;
}element;
struct node{
	element data;
	struct node* left_child,*right_child;	
};
typedef struct node* treePointer;
element* search(treePointer root,int k){
	if(!root) return NULL;
	if(k==root->data.key) return &(root->data);
	if(k<root->data.key) return search(root->left_child,k);
	return search(root->right_child,k);
}

treePointer modifiedSearch(treePointer node, int k){
	treePointer parent=NULL;
	while(node){
		if(k==node->data.key) return NULL;
		parent=node;
		if(k<node->data.key) node=node->left_child;
		else node=node->right_child;
	}
	return parent;
}
void inorder(treePointer root){
	if(root){
		inorder(root->left_child);
		printf("%d ",root->data.key);
		inorder(root->right_child);
	}
}

void preorder(treePointer root){
	if(root){
		printf("%d ",root->data.key);
		preorder(root->left_child);
		preorder(root->right_child);
	}
}

void postorder(treePointer root){
	if(root){
		postorder(root->left_child);
		postorder(root->right_child);
		printf("%d ",root->data.key);
	}
}

void insertNode(treePointer* node,int k){
//	node
	treePointer ptr,temp=modifiedSearch(*node,k);
//	treePointer ptr,temp=search(*node,k);
	
	if(temp|| !(*node) ){
		ptr=(treePointer)malloc(sizeof(*ptr));
		ptr->data.key=k;
		ptr->left_child=ptr->right_child=NULL;
		if(*node){
			if(k<temp->data.key) temp->left_child=ptr;
			else temp->right_child=ptr;
		}
		else *node=ptr;
		printf("node with key %d  inserted\n",k);
	}else{
		printf("key %d is alreay in the tree\n",k);
	}
}

void deleteNode(treePointer* node,int k){
	
}

int main(void){
	treePointer tree=NULL;
	insertNode(&tree,30);
	insertNode(&tree,40);
	insertNode(&tree,20);
	insertNode(&tree,50);
	insertNode(&tree,10);
//	inorder(tree);printf("\n");
//	preorder(tree);printf("\n");
	postorder(tree);printf("\n");
//	element* e=search(tree,30);
//	printf("%d ",e->key);
	return 0;
}
