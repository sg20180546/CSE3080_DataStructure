#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key;
} element;

struct node{
	struct node* llink;
	struct node* rlink;
	element item;
};
typedef struct node* node_pointer;

void dinsert(node_pointer,node_pointer);
void ddelete(node_pointer,node_pointer);
void dprint(node_pointer);



int main(void){
//	printf("%d\n",strcmp("hello","hello"));
	int i;
	node_pointer curr,head,newnode,delnode;
	head=(node_pointer)malloc(sizeof(struct node));
	head->item.key=-1;
	head->rlink=head;
	head->llink=head;
	
	curr=head;
	for(i=0;i<10;i++){
		newnode=(node_pointer)malloc(sizeof(struct node));
		newnode->item.key=i+1;
		newnode->rlink=NULL;
		newnode->llink=NULL;
		dinsert(curr,newnode);
		curr=newnode;
		dprint(head);
	}
	return 0;
}
void dinsert(node_pointer node,node_pointer newnode){
	newnode->llink=node;
	newnode->rlink=node->rlink;
	
	node->rlink->llink=newnode;
	node->rlink=newnode;
}

void ddelete(node_pointer node,node_pointer deleted){
	if(node==deleted) printf("cant delete head node\n");
	else{
		deleted->llink->rlink=deleted->rlink;
		deleted->rlink->llink=deleted->llink;
		free(deleted);
	}
}

void dprint(node_pointer head){
	node_pointer curr=head->rlink;
	while(curr!=head){
		printf("%2d ",curr->item.key);
		curr=curr->rlink;
	}
	printf("\n");
}
