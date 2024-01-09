#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX_SIZE 100
typedef struct{
	int vertices[MAX_SIZE];
	int adjMat[MAX_SIZE][MAX_SIZE];
	int size;
}GraphAdjMat;
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
	for(int i=0;i<=n;i++)	graph->adjMat[n][i]=graph->adjMat[i][n]=0;
	graph->size++;
}
void removeVertex(GraphAdjMat *graph,int index){
	if(index<0||index>=graph->size){
		printf("顶点索引越界\n");
		return ;
	}
	for(int i=index;i<graph->size-1;i++){
		graph->vertices[i]=graph->vertices[i+1];
	}
	for(int i=index;i<graph->size-1;i++){
		for(int j=0;j<graph->size;j++){
			graph->adjMat[i][j]=graph->adjMat[i+1][j];
		}
	}
	for(int i=0;i<graph->size;i++){
		for(int j=index;j<graph->size-1;j++)	graph->adjMat[i][j]=graph->adjMat[i][j+1];
	}
	graph->size--;
}
void addEdge(GraphAdjMat *graph,int i,int j){
	if(i<0||j<0||i>=graph->size||j>=graph->size||i==j){
		printf("边索引越界或相等\n");
		return ;
	}
	graph->adjMat[i][j]=1;
	graph->adjMat[j][i]=1;
}
void removeEdge(GraphAdjMat *graph,int i,int j){
	if(i<0||j<0||i>=graph->size||j>=graph->size||i==j){
		printf("边索引越界或相等\n");
		return ;
	}
	graph->adjMat[i][j]=0;
	graph->adjMat[j][i]=0;
}
int main(){
	GraphAdjMat *image=newGrapgAdjMat();
	addVertex(image,1);
	return 0; 
}
