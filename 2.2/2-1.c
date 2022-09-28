#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef struct{
	int data[MaxSize];
	int length;
}SqList;

int DeleteMinElem(SqList *L){
	int i,p,e;
	if(L->length<=0){
		printf("SqList is empty.\n");
		return 0;
	}
	for(i=1,p=0;i<L->length;i++){
		if(L->data[i]<L->data[p])
			p = i;
	}
	e = L->data[p];
	L->data[p]=L->data[L->length-1];
	L->length--;
	return e;
}

void InitList(SqList *L,int a[],int n){
	int i;
	for(i=0;i<n;i++){
		L->data[i] = a[i];
	}
	L->length=n;
}

void showList(SqList L){
	int i;
	for(i=0;i<L.length;i++){
		printf("%d\n",L.data[i]);
	}
}

int main(){
	SqList L;
	int a[]={1,2,3,4,5,6,7,8};
	InitList(&L,a,8);
	showList(L);
	printf("Deleted element:%d\n",DeleteMinElem(&L));
	showList(L);

	return 0;
}
