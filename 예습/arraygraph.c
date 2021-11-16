#include "arraygraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int i;

ArrayGraph* createAG(int max){
	ArrayGraph* pReturn = NULL;
	if(max>0){
		pReturn=(ArrayGraph*)malloc(sizeof(ArrayGraph));
		
		pReturn->graphType=GRAPH_UNDIRECTED;
		pReturn->maxVertexCnt=max;
	}else{
		printf("최대 노드 개수는 0보다 커야합니다.\n");
		return NULL;
	}
	
	pReturn->pVertex=(int*)malloc(sizeof(int)*max);
	memset(pReturn->pVertex,NOT_USED,sizeof(int)*max);
	
	
	
	pReturn->ppAdjEdge=(int**)malloc(sizeof(int*)*max);
	
	for(i=0;i<max;i++){
		pReturn->ppAdjEdge[i]=(int*)malloc(sizeof(int)*max);
	}
	
	for(i=0;i<max;i++){
		memset(pReturn->ppAdjEdge[i],0,sizeof(int)*max);
	}
	
	return pReturn;
}

ArrayGraph* createADG(int max){
	ArrayGraph* pReturn=NULL;
	pReturn=createAG(max);
	pReturn->graphType=GRAPH_DIRECTED;
	return pReturn;
}

int addVertexAG(ArrayGraph* pGraph, int newVertex){
	int ret=SUCCESS;
	
	if(pGraph!=NULL){
		if(newVertex<pGraph->maxVertexCnt && pGraph->pVertex[newVertex]==NOT_USED){
			pGraph->pVertex[newVertex]=USED;
			pGraph->curVertexCnt++;
		}else{
			printf("이미 존재하는 노드거나, 노드 개수를 초과했습니다");
			ret =FAIL;
		}
	}
	
	return ret;
}


int addEdgeWeightAG(ArrayGraph * pGraph,int fromVertex, int toVertex, int weight){
	int ret=SUCCESS;
	if(pGraph!=NULL){
		if(pGraph->pVertex[fromVertex]==USED && pGraph->pVertex[toVertex]==USED){
			if(pGraph->ppAdjEdge[fromVertex][toVertex]==0){
				pGraph->ppAdjEdge[fromVertex][toVertex]=weight;
				if(pGraph->graphType==GRAPH_UNDIRECTED){
					pGraph->ppAdjEdge[toVertex][fromVertex]=weight;
				}
			}else{
				printf("이미 존재하는 간선입니다");
				ret=FAIL;
			}
		}else{
			printf("시작 노드 혹은 종료 노드가 존재하지 않습니다");
			ret=FAIL;
		}
	}
	
	return ret;
}

int addEdgeAG(ArrayGraph* pGraph, int fromVertex, int toVertex){
	return addEdgeWeightAG(pGraph,fromVertex,toVertex,1);
}

int removeVertexAG(ArrayGraph* pGraph,int Vertex){
	int ret=SUCCESS;
	if(pGraph!=NULL){
		if(pGraph->pVertex[Vertex]==USED){
			for(i=0;i<pGraph->maxVertexCnt;i++){
				pGraph->ppAdjEdge[Vertex][i]=0;
				pGraph->ppAdjEdge[i][Vertex]=0;
			}
			pGraph->pVertex[Vertex]==NOT_USED;
			pGraph->curVertexCnt--;
		}else{
			printf("이미 존재하지 않는 노드입니다");
			ret=FAIL;
		}
	}
	return ret;
}

int removeEdgeAG(ArrayGraph* pGraph, int fromVertex, int toVertex){
	int ret=SUCCESS;
	if(pGraph!=NULL){
		if(pGraph->pVertex[fromVertex]==USED && pGraph->pVertex[toVertex]==USED){
			if(pGraph->ppAdjEdge[fromVertex][toVertex]!=0){
				pGraph->ppAdjEdge[fromVertex][toVertex]=0;
				if(pGraph->graphType==GRAPH_UNDIRECTED) pGraph->ppAdjEdge[toVertex][fromVertex]=0;
			}else{
				printf("이미 존재하지 않는 간선입니다");
				ret=FAIL;
			}
		}else{
			printf("시작 노드 혹은 종료 노드가 존재하지 않습니다 ");
			ret=FAIL;
		}
	}
}

int removeVertexAG_2(ArrayGraph* pGraph, int Vertex){
	int ret=SUCCESS;
	if(pGraph!=NULL){
		if(pGraph->pVertex[Vertex]==USED){
			for(i=0;i<pGraph->maxVertexCnt;i++){
				removeEdgeAG(pGraph,Vertex,i);
				removeEdgeAG(pGraph,i,Vertex);
			}
			pGraph->pVertex[Vertex]==NOT_USED;
			pGraph->curVertexCnt--;
		}else{
			printf("이미 존재하지 않는 노드입니다");
			ret=FAIL;
		}
	}
}

void deleteAG(ArrayGraph* pGraph){
	if(pGraph!=NULL){
		free(pGraph->pVertex);
		for(i=0;i<pGraph->maxVertexCnt;i++){
			free(pGraph->ppAdjEdge[i]);
		}
		free(pGraph->ppAdjEdge);
		free(pGraph);
	}
}

int main(void){
	ArrayGraph* root=createAG(5);
	addVertexAG(root,0);
	addVertexAG(root,1);
	addVertexAG(root,2);
	addVertexAG(root,3);
	addVertexAG(root,4);
	
	addEdgeAG(root,0,1);
	addEdgeAG(root,0,4);
	addEdgeAG(root,1,2);
	addEdgeAG(root,1,3);
	addEdgeAG(root,1,4);
	addEdgeAG(root,2,3);
	addEdgeAG(root,3,4);
	int j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%d ",root->ppAdjEdge[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}



//https://suyeon96.tistory.com/32
