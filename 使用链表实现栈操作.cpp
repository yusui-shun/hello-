#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct ListNode{
	int val;
	struct ListNode *next;
}ListNode;
typedef struct{
	ListNode *top;
	int size;
}LinkedListStack;
LinkedListStack *newLinkedListStack(void){
	LinkedListStack *s=(LinkedListStack*)malloc(sizeof(LinkedListStack));
	s->top=NULL;
	s->size=0;
	return s;
}
void delLinkedeListStack(LinkedListStack *s){
	while(s->top){
		ListNode *n=s->top->next;
		free(s->top);
		s->top=n;
	}
	free(s);
}
int size(LinkedListStack *s){
	assert(s);
	return s->size;
}
bool isEmpty(LinkedListStack *s){
	assert(s);
	return size(s)==0;
}
int peek(LinkedListStack *s){
	assert(s);
	return s->top->val; 
} 
void push(LinkedListStack *s,int num){
	assert(s);
	ListNode *node=(ListNode*)malloc(sizeof(ListNode));
	node->next=s->top; 
	node->val=num;
	s->top=node;
	s->size++;
} 
int pop(LinkedListStack *s){
	if(s->size==0){
		printf("stack is empty!\n");
		return 0;
	}
	assert(s);
	int val=peek(s);
	ListNode *tmp=s->top;
	s->top=s->top->next;
	free(tmp);
	s->size--;
	return val; 
}
int main(){
	LinkedListStack *s=newLinkedListStack();
	push(s,1);
	push(s,2);
	push(s,3);
	push(s,4);
	push(s,5);
	for(int i=0;i<5;i++) 	printf("%d\n",pop(s));
	push(s,1);
	push(s,2);
	push(s,3);
	push(s,4);
	push(s,5);
	printf("size长度为%d\n",size(s));
	pop(s);
	printf("size长度为%d\n",size(s));
	delLinkedeListStack(s);
	printf("size长度为%d\n",size(s));
	return 0;
} 

