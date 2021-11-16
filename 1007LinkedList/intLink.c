#include <stdio.h>
#include <stdlib.h>

struct listNode{
	int key;
	struct listNode* link;
};

struct listNode *head;
int find(int);
int length();
void printList();
int main(void){
	struct listNode* node, *prevNode=NULL;
	int i;
	for(i=10;i<=100;i+=10){
		node=malloc(sizeof(*node));
		node->key=i;
		node->link=NULL;
		if(prevNode==NULL) head=node;
		else prevNode->link=node;
		prevNode=node;
	}
	printList();
	
	
	printf("%d ",find(50) );
	return 0;
}

int find(int key){
	struct listNode* curr=head;
	int i=0;
	while(curr){
		if(curr->key==key) return i;
		i++;
		curr=curr->link;
	}
	
	return -1;
}
int length(){
	struct listNode* curr=head;
	int i=0;
	while(curr){
		i++;
		curr=curr->link;
	}
	return i;
}
void printList(){
	struct listNode* curr=head;
	int i=0;
	printf("printlist\n");
	while(curr){
	printf("%d ",curr->key);
	curr=curr->link;
	}
	printf("\n");
}
