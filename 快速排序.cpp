#include<stdio.h>
int arr[10]={6,2,9,8,1,0,4,5,3,7};
void swap(int nums[],int i,int j){
	int tmp=nums[i];
	nums[i]=nums[j];
	nums[j]=tmp;
}
int partition(int nums[],int left,int right){
	int i=left,j=right;
	while(i<j){
		while(i<j && nums[j]>=nums[left]){
			j-=1;
		}
		while(i<j && nums[i]<=nums[left]){
			i+=1;
		}
		swap(nums,i,j);
	}
	swap(nums,i,left);
	return i;
}
void quicksort(int nums[],int left, int right){
	if(left>=right) return ;
	int guard=partition(nums,left,right);
	quicksort(nums,left,guard-1);
	quicksort(nums,guard+1,right);
}
int main(){
	for(int i=0;i<10;i++){
		printf("arr[%d]是%d\n",i,arr[i]);
	}
	//printf("排序后的i是%d\n",partition(arr,0,9));
	quicksort(arr,0,9);
		for(int i=0;i<10;i++){
		printf("arr[%d]是%d\n",i,arr[i]);
	}
	return 0;
} 
