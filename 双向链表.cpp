#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode{
	int var;
	struct ListNode *prev;
	struct ListNode *next;
}ListNode;
ListNode *newListNode(int var){
	ListNode *node;
	node=(ListNode*)malloc(sizeof(ListNode));
	node->var=var;
	node->next=NULL;
	node->prev=NULL;
	return node;
}
ListNode *create_a_List(void){
	ListNode *n0=newListNode(1);
	ListNode *n1=newListNode(3);
	ListNode *n2=newListNode(2);
	ListNode *n3=newListNode(5);
	ListNode *n4=newListNode(4);
	n0->next=n1;
	n1->next=n2;
	n1->prev=n0;
	n2->next=n3;
	n2->prev=n1;
	n3->next=n4;
	n3->prev=n2;
	n4->prev=n3;
	return n0;
}
void insert(ListNode *n0,ListNode *p){
	ListNode *n1=n0->next;
	p->next=n1;
	p->prev=n0;
	n0->next=p;
	n1->prev=p;
}
void delete_node(ListNode *n0){
	if(!n0->next) return;
	ListNode *p=n0->next;
	ListNode *n1=p->next;
	n0->next=n1;
	n1->prev=n0;
	free(p);
}
ListNode *access(ListNode *n0,int index){
	while(n0&&n0->next&&index){
		n0=n0->next;
		index--;
	}
	return n0;
}
int find(ListNode *n0,int find){
	int index=0;
	while(n0){
		if(n0->var==find) return index;
		n0=n0->next;
		n0->next->prev=n0;
		index++;
	}
	return -1;
}
int main(){
	ListNode *n0=create_a_List();
	ListNode *p=newListNode(6);
	insert(n0,p);
	delete_node(n0);
	printf("输出第二个结点的数据%d\n",n0->next->var);
	printf("输出第2个结点的前后数据%d和%d\n",n0->var,n0->next->next->var);
	return 0;
} 
