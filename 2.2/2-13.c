#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int MinInt(int A[],int n){
		int i;
		int *B=(int*)malloc(n*sizeof(int));
		memset(B,0,n*sizeof(int));
		for(i=0;i<n;i++){
				if(A[i]>0&&A[i]<=n){
						B[A[i]-1]=1;
				}
		}
		for(i=0;i<n;i++){
				if(B[i]==0) break;
		}
		return i+1;
}

int main(){
		int A[]={-4,1,2,3,4};
		printf("%d\n",MinInt(A,5));
		return 0;
}
