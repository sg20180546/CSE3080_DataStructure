#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICIES 10000
#define INF 999999999
#define TRUE 1
#define FALSE 0

int numVertices;
int numEdges;
int cost[MAX_VERTICIES][MAX_VERTICIES];

int v;
int distance[MAX_VERTICIES];

void createGraph();
void createGraph2();
void createGraph3();
void bellmanFord();

void main(){
	int i,j;
	int path_curr,path_count;
	
	createGraph2();
//	createGraph3();
	for(i=0;i<numVertices;i++){
		distance[i]=INF;
	}
	v=0;
	bellmanFord();
	for(i=0;i<numVertices;i++){
		if(distance[i]!=INF){
			printf("src %d dst %d distance : %d\n",v,i,distance[i]);
		}else{
			printf("src %d dst %d distance --\n",v,i);
		}
	}
}

void bellmanFord(){
	int i,j,k;
	for(i=0;i<numVertices;i++){
		distance[i]=cost[v][i];
	}
	
	distance[v]=0;
	for(k=2;k<numVertices;k++){
		for(i=0;i<numVertices;i++){
			for(j=0;j<numVertices;j++){
				if(cost[i][j]==INF)	continue;
				if(distance[j]>cost[i][j]+distance[i]){
					distance[j]=cost[i][j]+distance[i];
				}	
			}
		}
	}
	
}


void createGraph() {
    int i, j;
    numVertices = 7;
    numEdges = 10;
    
    // cost adjacency matrix
    for(i=0; i<numVertices; i++) {
        for(j=0; j<numVertices; j++) {
            cost[i][j] = INF;
        }
    }

    cost[0][1] = 6;
    cost[0][2] = 5;
    cost[0][3] = 5;
    cost[1][4] = -1;
    cost[2][1] = -2;
    cost[2][4] = 1;
    cost[3][2] = -2;
    cost[3][5] = -1;
    cost[4][6] = 3;
    cost[5][6] = 3;
}

void createGraph2() {
    int i, j;
    numVertices = 4;
    numEdges = 4;
    
    // cost adjacency matrix
    for(i=0; i<numVertices; i++) {
        for(j=0; j<numVertices; j++) {
            cost[i][j] = INF;
        }
    }

    cost[0][1] = 3;
    cost[0][3] = 5;
    cost[2][1] = -6;
    cost[3][2] = 2;
}

void createGraph3(){
	int i,j;
	numVertices=6;
	numEdges=11;
	for(i=0;i<numVertices;i++){
		for(j=0;j<numVertices;j++){
			cost[i][j]=INF;
		}
	}
	cost[0][1] = 50;
    cost[0][2] = 45;
    cost[0][3] = 10;
    cost[1][3] = 15;
    cost[1][2] = 10;
    cost[2][4] = 30;
    cost[3][0] = 20;
    cost[3][4] = 15;
    cost[4][1] = 20;
    cost[4][2] = 35;
    cost[5][4] = 3;
}
