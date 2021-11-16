#include <stdio.h>
#include <stdlib.h>
struct listNode{
	char data;
	struct listNode* link;
};
struct listNode* first =NULL;

int main(void){
	struct listNode * newNode, *prevNode=NULL;
	struct listNode *currNode;
	char c;
	
	for(c='a';c<='e';c++){
		newNode=malloc(sizeof(*newNode));
		newNode->data=c;
		newNode->link=NULL;
		if(prevNode==NULL) first = newNode;
		else prevNode->link = newNode;
		prevNode=newNode;
	}
	
	currNode=first;
	while(currNode){
		printf("%c ",currNode->data);
		currNode=currNode->link;
	}
	printf("\n");
	
	currNode=first->link->link;
	printf("reading the 3rd ele : %c\n",currNode->data);
	
//	delete 3rd
	prevNode=first->link;
	currNode=prevNode->link;
	prevNode->link=prevNode->link->link;
	printf("deleting the 3rd ele\n");
	free(currNode);
//	printf
	currNode=first;
	while(currNode){
		printf("%c ",currNode->data);
		currNode=currNode->link;
	}
	printf("\n");
	
//	insert 'f' at 1st
	printf("insert 'f' at 1st\n");
	newNode=malloc(sizeof(*newNode));
	newNode->data='f';
	newNode->link=first;
	first=newNode;
	
	currNode=first;
	while(currNode){
		printf("%c ",currNode->data);
		currNode=currNode->link;
	}
	printf("\n");

// insert 't' at 3rd
	currNode=first;
	newNode=malloc(sizeof(*newNode));
	newNode->data='t';
	prevNode=currNode->link;
	newNode->link=prevNode->link;
	prevNode->link=newNode;
	printf("inserting t at 3rd\n");
	
	currNode=first;
	while(currNode){
		printf("%c ",currNode->data);
		currNode=currNode->link;
	}
	printf("\n");
	
// insert 'g' at the 1st;
	printf("inserting 'g' at 1st\n");
	newNode=malloc(sizeof(*newNode));
	newNode->data='g';
	newNode->link=first;
	first = newNode;

	currNode=first;
	while(currNode){
		printf("%c ",currNode->data);
		currNode=currNode->link;
	}
	printf("\n");
	
	return 0;
}
