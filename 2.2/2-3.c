#include<stdio.h>

typedef struct{
	int data[10];
	int length;
}SqList;

void deleteElem1(SqList *L,int e){
	int i,k;
	for(i=0,k=0;i<L->length;i++){
		if(L->data[i]!=e){
			L->data[k++]=L->data[i];
		}
	}
	L->length=k;
}

void deleteElem2(SqList *L,int e){
	int i,k;
	for(i=0,k=0;i<L->length;i++){
		if(L->data[i]==e){
			k++;
		}else{
			L->data[i-k]=L->data[i];
		}
	}
	L->length = L->length-k;
}

int main(){
	return 0;
}
