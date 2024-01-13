#include<stdio.h>
void insertSort(int nums[],int size){
	for(int i=1;i<size;i++){
		int base=nums[i],j=i-1;
		while(j>=0&&nums[j]>base){
			nums[j+1]=nums[j];
			j--;
		}
		nums[j+1]=base;
	}
}
int main(){
	int arr[6]={4,1,3,1,5,2};
	insertSort(arr,6);
	for(int i=0;i<6;i++){
		printf("%d\n",arr[i]);
	}
	return 0;
}
