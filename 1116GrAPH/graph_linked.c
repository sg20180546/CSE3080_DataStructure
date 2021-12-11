#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
struct node{
	int item;
	struct node* link;
};

typedef struct node* node_pointer;

node_pointer front[MAX_VERTICES], rear[MAX_VERTICES];

void main(){
	int numVerticies;
	int i,j;
	node_pointer temp;
	
	printf("how many verticies ? ");
	scanf("%d",&numVerticies);
	
	while(1){
		printf("enter edges");
		scanf("%d %d",&i,&j);
		if(i<0) break;
		
		temp = malloc(sizeof(struct node));
		temp->item=j;
		temp->link=NULL;
		if(front[i]){
			printf("rear[i]->link=temp;	\n");
		front[i]->link=temp;
		} 
		else{
			front[i]=temp;
			printf("front[i]=temp;\n");
		}
		rear[i]=temp;
		
		temp = malloc(sizeof(struct node));
		temp->item=i;
		temp->link=NULL;
		if(front[j]){
		front[j]->link=temp;	
		printf("rear[j]->link=temp;	\n");
		} 
		else{
		front[j]=temp;
		printf("front[j]=temp;\n");	
		} 
		rear[j]=temp;
	}
	for(i=0;i<numVerticies;i++){
		printf("%5d : ",i);
		temp=front[i];
		while(temp){
			printf("%5d",temp->item);
			temp=temp->link;
			if(temp) printf(" ->");
		}
		printf("\n");
	}
}
