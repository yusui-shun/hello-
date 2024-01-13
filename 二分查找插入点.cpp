 #include<stdio.h>
#include<stdlib.h>
int binarySerachInserttionSimple(int *nums,int len ,int target){
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
	return i;
}
int binarySerachInserttion(int *nums,int len ,int target){
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
	 		j=m-1;
	 	}
	}
	return i;
}
int main(){
	int arr[10]={0,1,2,3,4,5,6,7,8,9};
	printf("查找的元素为%d\n",binarySerachInserttionSimple(arr,10,7));
	return 0;
} 
