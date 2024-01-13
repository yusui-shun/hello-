#include<stdio.h>
void swap(int nums[],int i,int j){
	int temp=nums[i];
	nums[i]=nums[j];
	nums[j]=temp;
}
int partition(int nums[],int left,int right){
	int i=left,j=right;
	while(i<j){
		while(i<j&&nums[j]>=nums[left]){
			j--;
		}
		while(i<j&&nums[i]<=nums[left]){
			i++;
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
	int arr[6]={4,1,3,1,5,2};
	quicksort(arr,0,5);
	for(int i=0;i<6;i++){
		printf("%d\n",arr[i]);
	}
	return 0;
}
