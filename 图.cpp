#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct{
	int vertices[MAX_SIZE];
	int adjMat[MAX_SIZE][MAX_SIZE;
	int size;
}GraphAdjust;
GraphAdjMat *newGrapgAdjMat(){
	GraphAdjMat *graph=(GraphAdjMat*)malloc(sizeof(GraphAdjMat));
	graph->size=0;
	for(int i=0;i<MAX_SIZE;i++){
		for(int j=0;j<MAX_SIZE;j++){
			graph->adjMat[i][j]=0;
		}
	}
	return graph;
}
void delGraphAdjMat(GraphAdjMat *graph){
	free(graph);
}
int main(){
	return 0; 
}
