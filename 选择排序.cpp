#include<stdio.h>
void selectionSort(int nums[],int n){
	for(int i=0;i<n-1;i++){
		int k=i;
		for(int j=i+1;j<n;j++){
			if(nums[j]<nums[k]){
				k=j;
			}
			int temp=nums[i];
			nums[i]=nums[k];
			nums[k]=temp;
		}
	}
}
int main(){
	int arr[6]={4,1,3,1,5,2};
	selectionSort(arr,6);
	for(int i=0;i<6;i++){
		printf("%d\n",arr[i]);
	}
	return 0;
}
