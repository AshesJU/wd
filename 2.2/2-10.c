#include<stdio.h>
#include<stdbool.h>

bool reverse(int A[],int l,int r,int n){
		int i,j,temp;
		if(l<0||r>n-1) return false;
		for(i=l,j=r;i<j;i++,j--){
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;
		}
		return true;
}

bool Move_P_L(int A[],int p,int n){
		if(p<1||p>n-1) return false;
		reverse(A,0,p-1,n);
		reverse(A,p,n-1,n);
		reverse(A,0,n-1,n);
}

int main(){
		int A[]={1,2,3,4,5,6,7,8,9,10};
		Move_P_L(A,3,10);
		int i;
		for(i=0;i<10;i++){
				printf("%d\n",A[i]);
		}
		return 0;
}
