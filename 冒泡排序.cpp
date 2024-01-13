#include<stdio.h>
void bubbleSort(int nums[],int size){
	for(int i=size-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(nums[j]>nums[j+1]){
				int temp=nums[j];
				nums[j]=nums[j+1];
				nums[j+1]=temp;
			}
		}
	} 
}
void bubbleSortWithFlag(int nums[],int size){
	for(int i=size-1;i>0;i--){
		bool flag=false;
		for(int j=0;j<i;j++){
			if(nums[j]>nums[j+1]){
				int temp=nums[j];
				nums[j]=nums[j+1];
				nums[j+1]=temp;
				flag=true;
			}
		}
		if(!flag)	break;
	}
}
int main(){
	int arr[6]={4,1,3,1,5,2};
	bubbleSort(arr,6);
	for(int i=0;i<6;i++){
		printf("%d\n",arr[i]);
	}
	return 0;
}
