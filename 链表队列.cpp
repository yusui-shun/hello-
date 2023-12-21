#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct ListNode{
	int var;
	struct ListNode *next;
}ListNode;
ListNode *newListNode(int var){
	ListNode *node;
	node=(ListNode*)malloc(sizeof(ListNode));
	node->var=var;
	node->next=NULL;
}
typedef struct{
	ListNode *front,*rear;
	int queSize; 
}LinkedListQueue;
LinkedListQueue *newLinkedListQueue(void){
	LinkedListQueue *queue=(LinkedListQueue*)malloc(sizeof(LinkedListQueue));
	queue->front=NULL;
	queue->rear=NULL;
	queue->queSize=0;
	return queue; 
} 
void delLinkedListQueue(LinkedListQueue *queue){
	for(int i=0;i<queue->queSize&&queue->front!=NULL;i++){
		ListNode *tmp=queue->front;
		queue->front=queue->front->next;
		free(tmp);
	}
	free(queue);
}
int size(LinkedListQueue *queue){
	return queue->queSize;
}
bool empty(LinkedListQueue *queue){
	return (size(queue)==0);
}
void push(LinkedListQueue *queue,int num){
	ListNode *node=newListNode(num);
	if(queue->front==NULL){
		queue->front=node;
		queue->rear=node; 
	}
	else{
		queue->rear->next=node;
		queue->rear=node;
	}
	queue->queSize++;
}
int peek(LinkedListQueue *queue){
	assert(size(queue)&&queue->front);
	return queue->front->var; 
}
int pop(LinkedListQueue *queue){
	int num=peek(queue);
	ListNode *tmp=queue->front;
	queue->front=queue->front->next;
	free(tmp);
	queue->queSize--; 
	return num;
}
int main(){
	LinkedListQueue *queue=newLinkedListQueue();
	push(queue,1);
	push(queue,2);
	push(queue,3);
	push(queue,4);
	push(queue,5);
	pop(queue);
	printf("队列长度为%d\n",size(queue));
	printf("队首元素为%d\n",pop(queue));
	printf("队首元素为%d\n",peek(queue));
	return 0;
} 
