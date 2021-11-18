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
