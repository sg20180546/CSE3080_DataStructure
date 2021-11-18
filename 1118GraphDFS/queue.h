#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100
#define INVALID_KEY -1
typedef struct{
	int key;
} element;


int queue[MAX_QUEUE_SIZE];
int rear=0;
int front=0;

void addq(int);
int deleteq();
//void queueFull();
////int queueEmpty();
