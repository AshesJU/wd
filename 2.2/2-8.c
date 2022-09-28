#include<stdio.h>

#define MaxSize 100

typedef struct{
		int data[MaxSize];
		int length;
}SqList;

int reverse(int A[],int l,int r,int n){
		if(l>=r||r>=n) return 0;
		int i,j;
		int temp;
		for(i=l,j=r;i<j;i++,j--){
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;
		}
		return 1;
}

int swap(int A[],int a,int b,int n){
		//数组A[n]中,从0到a存放的顺序表和从a+1到a+b存放的顺序表位置互换。
		reverse(A,0,a-1,n);
		reverse(A,a,a+b-1,n);
		reverse(A,0,a+b-1,n);
		return 1;
}

int swap1(SqList *L,int m,int n){
		if(m+n>L->length) return 0;
		int i,j;
		int temp[m];
		for(i=0;i<m;i++){
				temp[i]=L->data[i];
		}
		for(i=0,j=m;i<n;i++,m++){
				L->data[i]=L->data[m];
		}
		for(i=0,j=n;i<m+n;i++,j++){
				L->data[j]=temp[i];
		}
		return 1;
}

int swap2(SqList *L,int m,int n){
		int i,j,k;
		int temp[n+m];
		for(i=0,j=m;i<n;i++,j++){
				temp[i]=L->data[j];
		}
		for(i=n,k=0;k<m;k++,i++){
				temp[i]=L->data[k];
		}
		for(i=0;i<n+m;i++){
				L->data[i]=temp[i];
		}
		return 1;
}

int main(){
		return 0;
}
