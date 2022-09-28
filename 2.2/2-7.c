#include<stdio.h>
#include<stdbool.h>

#define MaxSize 10

typedef struct{
		int data[MaxSize];
		int length;
}SqList;

bool merge(SqList A,SqList B,SqList *C){
		if((A.length+B.length)>MaxSize) return false;
		int i=0,j=0,k=0;
		C->length=0;
		while(i<A.length&&j<B.length){
				if(A.data[i]<B.data[j])
						C->data[k++]=A.data[i++];
				else
						C->data[k++]=B.data[j++];
		}
		while(i<A.length){
				C->data[k++]=A.data[i++];
		}
		while(j<B.length){
				C->data[k++]=B.data[j++];
		}
		C->length=A.length+B.length;
		return true;
		
}

int main(){
		return 0;
}
