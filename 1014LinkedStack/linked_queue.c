#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUES 10

#define IS_FULL(x) !x
#define IS_EMPTY(x) !x

typedef struct{
	int key;
} element;

struct queue{
	element item;
	struct queue* link;
};

typedef struct queue * queue_pointer;

queue_pointer front[MAX_QUEUES],rear[MAX_QUEUES];


void addq(queue_pointer*,queue_pointer*,element);
element deleteq(queue_pointer*);
void printQueue(queue_pointer);

int main(){
	int i;
	for(i=0;i<10;i++){
		element e;
		e.key=i+1;
		addq(&front[0],&rear[0],e);
		printQueue(front[0]);
	}
	
	for(i=0;i<10;i++){
		element e;
		e=deleteq(&front[0]);
		printQueue(front[0]);
	}
	
	return 0;	
}

void addq(queue_pointer *front,queue_pointer* rear,element item){
	queue_pointer temp=(queue_pointer)malloc(sizeof(struct queue));
	if(IS_FULL(temp)){
		fprintf(stderr,"queue is full");
		exit(1);
	}
	temp->item=item;
	temp->link=NULL;
	if(*front){
		(*rear)->link=temp;
		
	}else *front=temp;
	*rear=temp;
}
element deleteq(queue_pointer * front){
	queue_pointer temp=*front;
	element item;
	if(IS_EMPTY(*front)){
		fprintf(stderr,"queue is empty\n");
		exit(1);
	}
	item=temp->item;
	*front=temp->link;
	free(temp);
	return item;
}

void printQueue(queue_pointer front){
	queue_pointer temp=front;
	while(temp!=NULL){
		printf("%2d ",temp->item.key);
		temp=temp->link;
	}
	printf("\n");
}
