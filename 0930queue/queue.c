#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10
#define INVALID_KEY -1
//typedef struct{
//	int key;
//} element;

struct node{
	int vertex;
	struct node* link;
};

int queue[MAX_QUEUE_SIZE];
int rear=-1;
int front=-1;

void addq(int);
int deleteq();
//void queueFull();
//int queueEmpty();

//void main(){
//	int i;
//	element e;
//	for(i=0;i<8;i++){
//		e.key=i;
//		addq(e);
//		printf("key %2d inserted into the queue. (front: %2d rear: %2d)\n", e.key, front, rear);
//	}
//	for(i=0;i<8;i++){
//		e=deleteq();
//		printf("key %2d  deleted from the queue. (front: %2d rear: %2d)\n", e.key, front, rear);
//	}
//	
//	for(i=8;i<16;i++){
//		e.key=i;
//		addq(e);
//		printf("key %2d inserted into the queue. (front: %2d rear: %2d)\n", e.key, front, rear);
//	}
//	for(i=8;i<16;i++){
//		e=deleteq();
//		printf("key %2d  deleted from the queue. (front: %2d rear: %2d)\n", e.key, front, rear);
//	}
//}





void addq(int item){
//	if(rear==MAX_QUEUE_SIZE-1){
//		queueFull();
//	}
	queue[++rear]=item;
}
int deleteq(){
//	if(front==rear) return queueEmpty();
	return queue[++front];
}
void queueFull(){
	int i,offset;
	if(front==-1){
		fprintf(stderr, "no more space in the queue\n");
    	exit(1);
	}
	offset=front+1;
//	reorganaizing
	for(i=front+1;i<MAX_QUEUE_SIZE;i++){
		queue[i-offset]=queue[i];
	}
	
	front=front-offset;
	rear=rear-offset;
	printf(" ==== queue reorganized. (front: %2d rear: %2d) ====\n", front, rear);
}

int queueEmpty(){
	node e;
	e.vertex=INVALID_KEY;
	return e;
}
