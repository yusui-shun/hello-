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
TreeNode *search(TreeNode *root,int num){
	TreeNode *cur=root;
	while(cur != NULL){
		if(cur->val < num){
			cur=cur->right;
		}
		if(cur->val > num){
			cur=cur->left;
		}
		if(cur->val == num){
			break;
		}
	}
	return cur;
}
TreeNode *insert(TreeNode *root,int num){
	TreeNode *cur=root;
	if(cur==NULL){
		cur=newTreeNode(num);
		return cur;
	}
	TreeNode *pre=NULL;
	while(cur!=NULL){
		if(cur->val==num) 	return cur;
		pre=cur;
		if(cur->val<num){
			cur=cur->right;
		}else{
			cur=cur->left;
		}
	}
	TreeNode *node=newTreeNode(num);
	if(pre->val<num){
		pre->right=node;
	}else{
		pre->left=node;
	}
}
void removeItem(TreeNode *root,int num){
	if(root==NULL)	return;
	TreeNode *cur=root,*pre=NULL;
	while(cur!=NULL){
		if(cur->val==num)	break;
		pre=cur;
		if(cur->val<num){
			cur=cur->right;
		}else{
			cur=cur->left;
		}
	}
	if(cur==NULL) 	return;
	if(cur->left==NULL||cur->right==NULL){
		TreeNode *child=cur->left!=NULL?cur->left:cur->right;
		if(pre->left==cur){
			pre->left=child;
		}else{
			pre->right=child;
		}
	}
	else{
		TreeNode *tmp=cur->right;
		while(tmp->left!=NULL){
			tmp=tmp->left;
		}
		int tmpVal=tmp->val;
		removeItem(root,tmp->val);
		cur->val=tmpVal;
	}
}
int main(){
	TreeNode *n1=newTreeNode(3);
	TreeNode *n2=newTreeNode(4);
	TreeNode *n3=newTreeNode(6);
	TreeNode *n4=newTreeNode(2);
	TreeNode *n5=newTreeNode(5);
	n1->left=n2;
	n1->right=n3;
	n2->left=n4;
	n2->right=n5;
	insert(n1,7);
	removeItem(n1,7);
	//TreeNode *cur=search(n1,7);
	//printf("%d\n",cur->val);
	return 0;
}

