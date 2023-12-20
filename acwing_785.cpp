#include<stdio.h>
const int N=1e6+10;
int arr[N];
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
	int n;
	scanf("%d",&n);
	for(int j=0;j<n;j++) scanf("%d",&arr[j]);
	
		quicksort(arr,0,n-1);
		
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
	return 0;
} 
