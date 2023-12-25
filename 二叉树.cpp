#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX_SIZE 100
typedef struct TreeNode{
	int val;
	int height;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;
int *arr=(int*)malloc(sizeof(int)*MAX_SIZE);
TreeNode *newTreeNode(int val){
	TreeNode *node;
	node=(TreeNode*)malloc(sizeof(TreeNode));
	node->val=val;
	node->height=0;
	node->left=NULL;
	node->right=NULL;
	return node;
}
int *preOrder(TreeNode *root,int *size){
	if(root==NULL) return arr;
	arr[(*size)++]=root->val;
	preOrder(root->left,size);
	preOrder(root->right,size);
} 
int *inOrder(TreeNode *root,int *size){
	if(root==NULL) return arr;
	inOrder(root->left,size);
	arr[(*size)++]=root->val;
	inOrder(root->right,size);
}
int *postOrder(TreeNode *root,int *size){
	if(root==NULL) return arr;
	postOrder(root->left,size);
	postOrder(root->right,size);
	arr[(*size)++]=root->val;
}
int *leverOrder(TreeNode *root,int *size){
	int front=0,rear=0;
	int index;
	TreeNode *node;
	TreeNode **queue;
	queue=(TreeNode**)malloc(sizeof(TreeNode*)*MAX_SIZE);
	queue[rear++]=root;
	index=0;
	while(front<rear){
		node=queue[front++];
		arr[index++]=node->val;
		if(node->left!=NULL){
			queue[rear++]=node->left;
		}
		if(node->right!=NULL){
			queue[rear++]=node->right;
		}
	}
	*size=index;
	//arr=realloc(arr,sizeof(int)*(*size));
	free(queue);
	return arr;
}
int main(){
	TreeNode *n1=newTreeNode(1);
	TreeNode *n2=newTreeNode(2);
	TreeNode *n3=newTreeNode(3);
	TreeNode *n4=newTreeNode(4);
	TreeNode *n5=newTreeNode(5);
	n1->left=n2;
	n1->right=n3;
	n2->left=n4;
	n2->right=n5;
	int Size=0;
	//arr=leverOrder(n1,&Size);
	inOrder(n1,&Size);
	for(int i=0;i<5;i++)	printf("%d\n",arr[i]);
	return 0;
}

