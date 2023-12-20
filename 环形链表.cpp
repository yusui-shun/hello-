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
	n4->next=n0; 
	return n0;
}
void insert(ListNode *n0,ListNode *p){
	ListNode *n1=n0->next;
	p->next=n1;
	n0->next=p;
}
void delete_list(ListNode *n0){
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
/*int find(ListNode *n0,int find){
	int index=0;
	int maxiteration=1000;//ʹ�������Ҵ�����������������Ҳ�������ѭ��  
	while(n0&&maxiteration>0){
		if(n0->var==find) return index;
		n0=n0->next;
		maxiteration--;
		index++;
	}
	return -1;
}*/ 
int find(ListNode *n0,int find){
	int index=0;
	ListNode *fast=n0->next,*slow=n0;
	while(n0&&fast!=slow){
		if(n0->var==find) return index;
		n0=n0->next;
		fast=fast->next;
		fast=fast->next;
		slow=slow->next;
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
	int find_index=find(n0,7);
	printf("����±�Ϊ1�Ľ�������%d\n",n->var);
	printf("����ڶ�����������%d\n",n0->next->var);
	printf("�������Ϊ5�Ľ����±�%d\n",find_index);
	return 0;
}
