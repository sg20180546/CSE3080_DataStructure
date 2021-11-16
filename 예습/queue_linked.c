#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	int Info;
	struct _Node* Next;
}Node;

// front부터 DEL, back부터 INSERT
Node* front=NULL;
Node* back=NULL;
int count=0;


int isEmptyQueue(){
	return count==0;
}

void Enqueue(int x){
	Node* NewCell = (Node*)malloc(sizeof(Node));
	(*NewCell).Info=x;
	(*NewCell).Next=NULL;
	if(isEmptyQueue())
	{
		front=NewCell; 
		back=NewCell;
	} 
	else{
	(*back).Next=NewCell;
	back=NewCell;
	}
	count++;
}
int Dequeue(){
	if(isEmptyQueue() ) return;
	int tmp=Front();
	Node* temp=front;
	front=(*front).Next;
	count--;
	free(temp);
	return tmp;
}

int Front(){
	if(isEmptyQueue()) {
		return ;
	}
	return (*front).Info;
}


int main(void){
	Enqueue(13);
	Enqueue(33);
	Enqueue(65);
	Enqueue(123);
	Enqueue(44);
	printf("%d\n",Front() );
	printf("%d\n", Dequeue() );
	printf("%d\n",Dequeue());
	printf("%d\n",Dequeue());
	printf("%d\n",Dequeue());
	printf("%d\n",Dequeue());
	
	return 0;
}
