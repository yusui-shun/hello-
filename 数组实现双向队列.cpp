#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct{
	int *nums;
	int front;
	int queSize;
	int queCapacity; 
}ArrayDeque;
ArrayDeque *newArrayDeque(int capacity){
	ArrayDeque *deque=(ArrayDeque*)malloc(sizeof(ArrayDeque));
	deque->queCapacity=capacity;
	deque->nums=(int*)malloc(sizeof(int)*deque->queCapacity);
	deque->front=deque->queSize=0;
	return deque;	 
} 
void delArrayDeque(ArrayDeque *deque){
	free(deque->nums);
	free(deque);
}
int capacity(ArrayDeque *deque){
	return deque->queCapacity;
}
int size(ArrayDeque *deque){
	return deque->queSize;
}
bool empty(ArrayDeque *deque){
	return deque->queSize==0;
}
int dequeIndex(ArrayDeque *deque,int i){
	return ((i+capacity(deque))%capacity(deque));
}
void pushFront(ArrayDeque *deque,int num){
	if(deque->queSize==capacity(deque)){
		printf("队列已满\n");
		return;
	}
	deque->front=dequeIndex(deque,deque->front-1);
	deque->nums[deque->front]=num;
	deque->queSize++; 
}
void pushRear(ArrayDeque *deque,int num){
	if(deque->queSize==capacity(deque)){
		printf("双向队列已满\n");
		return;
	}
	int rear=dequeIndex(deque,deque->front+deque->queSize);
	deque->nums[rear]=num;
	deque->queSize++;
}
int peekFront(ArrayDeque *deque){
	assert(empty(deque)==0);
	return deque->nums[deque->front];
}
int peekRear(ArrayDeque *deque){
	assert(empty(deque)==0);
	int last=dequeIndex(deque,deque->front+deque->queSize-1);
	return deque->nums[last];
}
int popFront(ArrayDeque *deque){
	int num=peekFront(deque);
	deque->front=dequeIndex(deque,deque->front+1);
	deque->queSize--;
	return num;
}
int popRear(ArrayDeque *deque){
	int num=peekRear(deque);
	deque->queSize--;
	return num;
}
int main(){
	
	return 0;
}
