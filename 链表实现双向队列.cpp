#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct ListNode{
	int val;
	struct ListNode *next;
	struct ListNode *prev;
}ListNode;
ListNode *newListNode(int val){
	ListNode *node;
	node=(ListNode*)malloc(sizeof(ListNode));
	node->val=val;
	node->next=NULL;
	node->prev=NULL;
	return node;
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
	for(int i=0;i<queue->queSize && queue->front!=NULL;i++){
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
void RearPush(LinkedListQueue *queue,int num){
	ListNode *node=newListNode(num);
	if(queue->front==NULL){
		queue->front=node;
		queue->rear=node;
	}
	else{
		node->prev=queue->rear;
		queue->rear->next=node;
		queue->rear=node;
	}
	queue->queSize++;
}
void FrontPush(LinkedListQueue *queue,int num){
	ListNode *node=newListNode(num);
	if(queue->front==NULL){
		queue->front=node;
		queue->rear=node;
	}
	else{
		node->next=queue->front;
		queue->front->prev=node;
		queue->front=node;
	}
	queue->queSize++;
}
int FrontPeek(LinkedListQueue *queue){
	assert(size(queue)&&queue->front);
	return queue->front->val;
} 
int RearPeek(LinkedListQueue *queue){
	assert(size(queue)&&queue->front);
	return queue->rear->val;
}
int FrontPop(LinkedListQueue *queue){
	int num=FrontPeek(queue);
	ListNode *tmp=queue->front;
	queue->front=queue->front->next;
	free(tmp);
	queue->queSize--;
	return num;
}
int RearPop(LinkedListQueue *queue){
	int num=RearPeek(queue);
	ListNode *tmp=queue->rear;
	queue->rear=queue->rear->prev;
	free(tmp);
	queue->queSize--;
	return num;
} 
int main(){
	LinkedListQueue *queue=newLinkedListQueue();
	FrontPush(queue,1);
	FrontPush(queue,2);
	FrontPush(queue,3);
	//FrontPop(queue);
	//RearPop(queue);
	printf("队列长度为%d\n",size(queue));
	printf("队列首元素为%d\n",FrontPeek(queue));
	printf("队列尾元素为%d\n",RearPeek(queue));
	return 0;
} 
