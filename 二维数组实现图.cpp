#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX_SIZE 100
typedef struct{
	int vertices[MAX_SIZE];
	int adjMat[MAX_SIZE][MAX_SIZE];
	int size;
}GraphAdjMat;
<<<<<<< HEAD:二维数组实现图.cpp
GraphAdjMat *newGrapgAdjMat(){
=======
GraphAdjMat *newGraphAdjMat(){
>>>>>>> refs/remotes/origin/main:图.cpp
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
		printf("ͼ�Ķ��������Ѿ��ﵽ���ֵ\n");
		return ;
	}
	int n=graph->size;
	graph->vertices[n]=val;
<<<<<<< HEAD:二维数组实现图.cpp
	for(int i=0;i<=n;i++)	graph->adjMat[n][i]=graph->adjMat[i][n]=0;
=======
	for(int i=0;i<=n;i++){
		graph->adjMat[n][i]=graph->adjMat[i][n]=0;
	}
>>>>>>> refs/remotes/origin/main:图.cpp
	graph->size++;
}
void removeVertex(GraphAdjMat *graph,int index){
	if(index<0||index>=graph->size){
		printf("��������Խ��\n");
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
<<<<<<< HEAD:二维数组实现图.cpp
		for(int j=index;j<graph->size-1;j++)	graph->adjMat[i][j]=graph->adjMat[i][j+1];
	}
	graph->size--;
}
void addEdge(GraphAdjMat *graph,int i,int j){
	if(i<0||j<0||i>=graph->size||j>=graph->size||i==j){
		printf("������Խ������\n");
		return ;
	}
	graph->adjMat[i][j]=1;
	graph->adjMat[j][i]=1;
}
void removeEdge(GraphAdjMat *graph,int i,int j){
	if(i<0||j<0||i>=graph->size||j>=graph->size||i==j){
		printf("������Խ������\n");
		return ;
	}
	graph->adjMat[i][j]=0;
	graph->adjMat[j][i]=0;
}
int main(){
	GraphAdjMat *image=newGrapgAdjMat();
	addVertex(image,1);
=======
		for(int j=index;j<graph->size-1;j++){
			graph->adjMat[i][j]=graph->adjMat[i][j+1]; 
		}
	}
	graph->size--;
}
void addEdge(GraphAdjMat *graph,int i,int j){
	if(i<0||j<0||i>=graph->size||j>=graph->size||i==j){
		printf("����߽�Խ��\n");
		return;
	}
	graph->adjMat[i][j]=1;
	graph->adjMat[j][i]=1;
}
void removeEdge(GraphAdjMat *graph,int i,int j){
	if(i<0||j<0||i>=graph->size||j>=graph->size||i==j){
		printf("����߽�Խ��\n");
		return;
	}
	graph->adjMat[i][j]=0;
	graph->adjMat[j][i]=0;
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // ������arr������ָ��ʹ��
    }
}
void printgraphAdjMat(GraphAdjMat *graph){
	printf("�����б� = ");
	printArray(graph->vertices,graph->size);
	printf("�ڽӾ��� =\n");
	for(int i=0;i<graph->size;i++){
		printArray(graph->adjMat[i],graph->size);
	} 
} 
int main(){  
	GraphAdjMat *graph=newGraphAdjMat();
	addVertex(graph,1);
	addVertex(graph,2);
	addVertex(graph,3);
	addVertex(graph,4);
	addVertex(graph,5);
	printgraphAdjMat(graph);
>>>>>>> refs/remotes/origin/main:图.cpp
	return 0; 
}
