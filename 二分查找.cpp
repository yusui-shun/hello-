#include<stdio.h>
#include<stdlib.h>
#define N 100
int binarySerach(int *nums,int len ,int target){
	int i=0,j=len-1;
	while(i<=j){
		int m=i+(j-i)/2;
		if(nums[m]<target){
			i=m+1;
		}
		else if(nums[m]>target){
			j=m-1;
		}
		else{
	 		return m;
	 	}
	}
	return -1;
}
int binarySerachLCRO(int *nums,int len,int target){
	int i=0,j=len;
	while(i<j){
		int m=i+(j-i)/2;
		if(nums[m]<target){
			i=m+1;
		}
		else if(nums[m]>target){
			j=m;
		}
		else{
			return m;
		}
	}
	return -1;
} 
int main(){
	int arr[10]={0,1,2,3,4,5,6,7,8,9};
	printf("查找的元素为%d\n",binarySerach(arr,10,7));
	return 0;
} 
