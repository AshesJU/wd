#include<stdio.h>

int SearchExchangeInsert(int A[],int x,int n){
		int i;
		int low=0;
		int high=n-1;
		int mid;
		while(low<=high){
				mid=(low+high)/2;
				if(A[mid]==x) break;
				else if(A[mid]<x) low=mid+1;
				else high=mid-1;
		}
		if(A[mid]==x&&mid!=n-1){
				A[mid]=A[mid+1];
				A[mid+1]=x;
		}
		if(low>high){
				for(i=n-1;i>high;i--){
						A[i+1]=A[i];
				}
				A[i+1]=x;
		}
}

int main(){
		return 0;
}
