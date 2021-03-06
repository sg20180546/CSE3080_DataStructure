#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICIES 100
#define MIN2(x,y) ((x) < (y) ? (x) : (y))

struct node{
	int vertex;
	struct node* link;
};

typedef struct node* nodePointer;

nodePointer graph[MAX_VERTICIES];
int dfn[MAX_VERTICIES];
int low[MAX_VERTICIES];
int num;
int n;

void createGraph();
void init();
void dfnlow(int,int);
int checkAp(int);

int main(){
	int i;
	createGraph();
	init();
	dfnlow(3,-1);
	
	for(i=0;i<10;i++) printf("%d ",dfn[i]);
	printf("\n");
	for(i=0;i<10;i++) printf("%d ",low[i]);
	printf("\n");
	for(i=0;i<n;i++){
		printf("dfn[%d] : %d low[%d] : %d ",i,dfn[i],i,low[i]);
		if(checkAp(i)) printf("Arcticulation point");
		printf("\n");
	}
	
	return 0;
}

void init(){
	int i;
	for(i=0; i<n;i++){
		dfn[i]=low[i]=-1;
		
	}
	num=0;
}

void dfnlow(int u, int v){
	nodePointer ptr;
	int w;
	dfn[u]=low[u]=num++;
	
	for(ptr=graph[u];ptr;ptr=ptr->link){
		w=ptr->vertex;
//		w -> adjacent list(child or parent)
//		v - > parent node

		if(dfn[w]<0){
//			if not visitied, do dfs
			dfnlow(w,u);
			low[u]=MIN2(low[u],low[w]);
		}else if(w!=v){
//			if(w==child)
			printf("u(%d) w(%d),v(%d) : low[%d]=MIN2(low[%d](%d) ,dfn[%d](%d) )\n",u,w,v,u,u,low[u],w,dfn[w]);
//			low[u] is  
			low[u]=MIN2(low[u],dfn[w]);
		}
	}
}

int checkAp(int u){
	if(dfn[u]==0){
//		printf("\ndfn[%d] =0\n",u);
		int nChild=0;
		nodePointer ptr=graph[u];
		while(ptr){
			nChild++;
			ptr=ptr->link;
		}
		
		if(nChild>1) return TRUE;
		else return FALSE;
	}
	else{
		nodePointer ptr=graph[u];
		while(ptr){
//			child node일때 
			if(dfn[ptr->vertex]>dfn[u]){
//			child node의 low값이 current node의 방문순위보다 늦을때 
				if(low[ptr->vertex] >= dfn[u]) return TRUE;
			}
			
			ptr=ptr->link;
			
		}	
		return FALSE;
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

