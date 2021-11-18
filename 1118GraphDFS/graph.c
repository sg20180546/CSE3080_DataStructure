#include <stdio.h>
#include <stdlib.h>
#include "queue.c"
#define MAX_VERTEX 100
#define TRUE 1
struct node{
	int vertex;
	struct node* link;
};
typedef struct node* nodePointer;

nodePointer graph[MAX_VERTEX];
int visited[MAX_VERTEX];

void dfs(int v);
void bfs(int v);

int main(){
	nodePointer prev,np;
	
 /* adjacency list for vertex 0 */
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 1; np->link = NULL; graph[0] = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 2; np->link = NULL; prev->link = np;

    /* adjacency list for vertex 1 */
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 0; np->link = NULL; graph[1] = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 3; np->link = NULL; prev->link = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 4; np->link = NULL; prev->link = np;

    /* adjacency list for vertex 2 */
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 0; np->link = NULL; graph[2] = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 5; np->link = NULL; prev->link = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 6; np->link = NULL; prev->link = np;

    /* adjacency list for vertex 3 */
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 1; np->link = NULL; graph[3] = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 7; np->link = NULL; prev->link = np;

    /* adjacency list for vertex 4 */
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 1; np->link = NULL; graph[4] = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 7; np->link = NULL; prev->link = np;

    /* adjacency list for vertex 5 */
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 2; np->link = NULL; graph[5] = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 7; np->link = NULL; prev->link = np;

    /* adjacency list for vertex 6 */
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 2; np->link = NULL; graph[6] = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 7; np->link = NULL; prev->link = np;

    /* adjacency list for vertex 7 */
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 3; np->link = NULL; graph[7] = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 4; np->link = NULL; prev->link = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 5; np->link = NULL; prev->link = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 6; np->link = NULL; prev->link = np;
	
	
	int i;
	for(i=0;i<8;i++) visited[i]=0;

	dfs(0);	
	printf("\n");
	for(i=0;i<8;i++) visited[i]=0;
	bfs(0);
	return 0;
}

void dfs(int v){
	nodePointer w;
	visited[v]=1;
	printf("%5d ",v);
	for(w=graph[v];w;w=w->link){
		if(!visited[w->vertex]) dfs(w->vertex);
	}
}
void bfs(int v){
	nodePointer w;
//	front =rear=-1;
	printf("%5d ",v);
	visited[v]=TRUE;
	addq(v);
//	printf("front : %d, rear : %d \n ",front,rear);//
	while(front!=rear){
		v=deleteq();
		for(w=graph[v];w;w=w->link){
			
			if(!visited[w->vertex]){
				printf("%5d ",w->vertex);
				addq(w->vertex);
				visited[w->vertex]=TRUE;
			}
		}
	}
}


