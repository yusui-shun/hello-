#include<stdio.h>
#include<stdlib.h>
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
ListNode *create_a_List(void){
	ListNode *n0=newListNode(1);
	ListNode *n1=newListNode(3);
	ListNode *n2=newListNode(2);
	ListNode *n3=newListNode(5);
	ListNode *n4=newListNode(4);
	n0->next=n1;
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	return n0;
}
void insert(ListNode *n0,ListNode *p){
	ListNode *n1=n0->next;
	p->next=n1;
	n0->next=p;
}
void delete_list(ListNode *n0){
	if(!n0->next) return;
	ListNode *p=n0->next;
	ListNode *n1=p->next;
	n0->next=n1;
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
		index++;
	}
	return -1;
}
int main(){
	ListNode *n0=create_a_List();
	ListNode *p=newListNode(6);
	insert(n0,p);
	delete_list(n0);
	ListNode *n=access(n0,1);
	int find_index=find(n0,5); 
	printf("输出下标为1的结点的数据%d\n",n->var);
	printf("输出第二个结点的数据%d\n",n0->next->var);
	printf("输出数据为5的结点的下标%d\n",find_index);
	return 0;
}
