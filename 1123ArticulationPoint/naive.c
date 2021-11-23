#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICIES 100

struct node{
	int vertex;
	struct node* link;
};

typedef struct node* nodePointer;
void createGraph();
nodePointer graph[MAX_VERTICIES];
int n;
int visited[MAX_VERTICIES];
void dfs(int v);


int main(){
	int i,k;
	createGraph();
	for(k=0;k<n;k++){
		for(i=0;i<n;i++) visited[i]=0;
//		removing point k
		visited[k]=1;
		
		if(k==0) dfs(1);
		else dfs(0);
//		for(i=0;i<n;i++) printf("%d ",visited[i]);
//		printf("\n");
		for(i=0;i<n;i++){
			if(visited[i]==0){
				printf("%d is an articulation point\n",k);
				break;
			}
		}
	}
	return 0;
}



void dfs(int v){
	nodePointer w;
	visited[v]=1;
	for(w=graph[v];w;w=w->link){
		if(!visited[w->vertex]){
			dfs(w->vertex);
		}
	}
}


void createGraph() {
    nodePointer prev;
    nodePointer np;

    /* adjacency list for vertex 0 */
    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 1;
    np->link = NULL;
    graph[0] = np;

    /* adjacency list for vertex 1 */
    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 0;
    np->link = NULL;
    graph[1] = np;
    prev = np;
    
    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 2;
    np->link = NULL;   
    prev->link = np;
    prev = np;

    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 3;
    np->link = NULL;   
    prev->link = np;

    /* adjacency list for vertex 2 */
    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 1;
    np->link = NULL;
    graph[2] = np;
    prev = np;
    
    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 4;
    np->link = NULL;   
    prev->link = np;

    /* adjacency list for vertex 3 */
    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 4;
    np->link = NULL;
    graph[3] = np;
    prev = np;
    
    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 1;
    np->link = NULL;   
    prev->link = np;
    prev = np;

    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 5;
    np->link = NULL;   
    prev->link = np;

    /* adjacency list for vertex 4 */
    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 2;
    np->link = NULL;
    graph[4] = np;
    prev = np;
    
    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 3;
    np->link = NULL;   
    prev->link = np;
    
    /* adjacency list for vertex 5 */
    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 3;
    np->link = NULL;
    graph[5] = np;
    prev = np;
    
    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 6;
    np->link = NULL;   
    prev->link = np;
    prev = np;

    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 7;
    np->link = NULL;   
    prev->link = np;

    /* adjacency list for vertex 6 */
    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 5;
    np->link = NULL;
    graph[6] = np;
    prev = np;
    
    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 7;
    np->link = NULL;   
    prev->link = np;
    
    /* adjacency list for vertex 7 */
    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 5;
    np->link = NULL;
    graph[7] = np;
    prev = np;
    
    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 6;
    np->link = NULL;   
    prev->link = np;
    prev = np;

    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 9;
    np->link = NULL;   
    prev->link = np;
    prev = np;

    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 8;
    np->link = NULL;   
    prev->link = np;

    /* adjacency list for vertex 8 */
    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 7;
    np->link = NULL;
    graph[8] = np;

    /* adjacency list for vertex 9 */
    np = (nodePointer)malloc(sizeof(struct node));
    np->vertex = 7;
    np->link = NULL;
    graph[9] = np;

    n = 10;
}

