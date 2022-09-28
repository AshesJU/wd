#include<stdio.h>
#include<stdlib.h>

#define InitSize 10

typedef struct{
	int *data;
	int length;
	int MaxSize;
}SeqList;

void InitList(SeqList *L){
	L->data = (int*)malloc(InitSize*sizeof(int));
	L->length = 0;
	L->MaxSize = InitSize;
}

void IncreaseSize(SeqList *L,int len){
	int i;
	int *p = L->data;
	L->data = (int*)malloc((len+L->MaxSize)*sizeof(int));
	L->MaxSize = len + L->MaxSize;
	for(i=0;i<L->length;i++){
		L->data[i] = p[i];
	}
	free(p);
}

int main(){
	SeqList L;
	InitList(&L);
	IncreaseSize(&L,5);

	return 0;
}
