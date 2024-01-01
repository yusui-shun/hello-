#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct{
	int vertices[MAX_SIZE];
	int adjMat[MAX_SIZE][MAX_SIZE;
	int size;
}GraphAdMat;
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
void addVertex(GraphAdjMat *graph,int val){
	if(graph->size==MAX_SIZE){
		printf("图的顶点数量已经达到最大值\n");
		return ;
	}
	int n=graph->size;
	graph->vertices[n]=val;
	for(int i=0;i<=n;i++)	graph->adjMat[n][j]=graph->adjMat[i][n]=0;
	graph->size++;
}
void removeVertex(GraphAdjMat *graph,int index){
	if(index<0||index>=graph->size){
		printf("顶点索引越界\n");
		return ;
	}
	for(int i=index;i<graph->sizz-1;i++){
		graph->vertices[i]=graph->vertices[i+1];
	}
	for(int i=index;i<graph->size-1;i++){
		for(int j=0;j<graph->size;j++){
			graph->adjMat[i][j]=graph->adjMat[i+1][j];
		}
	}
	for(int i=0;i<graph->size;i++){
		for(int j=index)
	}
}
int main(){
	1
	return 0; 
}
