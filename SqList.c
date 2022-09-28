#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 10

typedef struct{
	int length;
	int data[MaxSize];
}SqList;

void InitList(SqList *L){
	int i;
	for(i=0;i<MaxSize;i++){
		L->data[i]=0;
	}
	L->length=0;
}

void showList(SqList L){
	int i;
	for(i=0;i<L.length;i++){
		printf("%d\n",L.data[i]);
	}
}

bool ListInsert(SqList *L,int i,int e){
	if(i<1||i>L->length+1) return false;
	if(L->length >= MaxSize) return false;
	int j;
	for(j=L->length;j>=i;j--){
		L->data[j]=L->data[j-1];
	}
	L->data[i-1]=e;
	L->length++;
	return true;
}

bool ListDelete(SqList *L,int i,int *e){
	if(i<1||i>L->length) return false;
	int j;
	*e = L->data[i-1];
	for(j=i;j<L->length;j++){
		L->data[j-1]=L->data[j];
	}
	L->length--;
	return true;
}

int main(){
	SqList L;
	int e = -1;
	InitList(&L);
	ListInsert(&L,1,1);
	showList(L);
	if(ListDelete(&L,1,&e)) printf("No.%d has been deleted from SqList,whose value was %d\n",1,e);
	else printf("illegal position,fail to delete.\n");
	return 0;
}
