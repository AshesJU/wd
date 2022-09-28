#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef struct{
	int data[MaxSize];
	int length;
}SqList;

void ReverseList(SqList *L){
	int temp;
	int i,j;
	for(i=0,j=L->length-1;i<j;i++,j--){
		temp=L->data[i];
		L->data[i]=L->data[j];
		L->data[j]=temp;
	}
}

int main(){
	return 0;
}
