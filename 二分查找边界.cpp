 #include<stdio.h>
 int binarySerachInsertion(int *nums,int len ,int target){
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
int binarySerachleftEdge(int *nums,int numSize,int target){
	int i=binarySerachInsertion(nums,numSize,target);
	if(i==numSize||nums[i]!=target){
		return -1;
	}
} 
int binarySerachRightEdge(int *nums,int numSize,int target){
	int i=binarySerachInsertion(nums,numSize,target+1);
	int j=i-1;
	if(j==-1||nums[j]!=target){
		return -1;
	}
	return j;
}
int main(){
	int arr[10]={0,1,2,3,4,5,6,7,8,9};
	printf("查找的元素为%d\n",binarySerachRightEdge(arr,10,7));
	return 0;
	return 0;
}
