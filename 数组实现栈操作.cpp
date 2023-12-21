#include<stdio.h> 
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct{
	int *data;
	int size;
}ArrayStack;
ArrayStack *newArrayStack(void){
	ArrayStack *stack=(ArrayStack*)malloc(sizeof(ArrayStack));
	stack->data=(int*)malloc(sizeof(int)*MAX_SIZE);
	stack->size=0;
	return stack;
}
void delArrayStack(ArrayStack *stack){
	free(stack->data);
	free(stack);
}
int size(ArrayStack *stack){
	return stack->size;
}
bool isEmpty(ArrayStack *stack){
	return stack->size==0;
}
void push(ArrayStack *stack,int num){
	if(stack->size==MAX_SIZE){
		printf("stack is full\n");
		return;
	}
	stack->data[stack->size]=num;
	stack->size++;
}
int peek(ArrayStack *stack){
	if(stack->size==0){
		printf("stack is empty\n");
		return -1;
	}
	return stack->data[stack->size-1];
}
int pop(ArrayStack *stack){
	if(stack->size==0){
		printf("stack is empty\n");
		return -1;
	}
	int val=peek(stack);
	stack->size--;
	return val;
}
int main(){
	ArrayStack *stack=newArrayStack();
	push(stack,1);
	push(stack,2);
	push(stack,3);
	push(stack,4);
	push(stack,5);
	printf("栈顶元素为%d\n",peek(stack));
	for(int i=0;i<5;i++) 	printf("%d\n",pop(stack));
	push(stack,1);
	push(stack,2);
	push(stack,3);
	push(stack,4);
	push(stack,5);
	printf("size长度为%d\n",size(stack));
	pop(stack);
	printf("size长度为%d\n",size(stack));
	delArrayStack(stack);
	printf("size长度为%d\n",size(stack));
	return 0;
}
