#include<stdio.h>

typedef struct{
		int data[10];
		int length;
}SqList;

int DelReElem1(SqList *L){
		if(L->length<=1) return 0;
		int i=1;
		int k=0;
		while(i<L->length){
				if(L->data[i]==L->data[i-1]){
						k++;
				}else{
						L->data[i-k]=L->data[i];
				}
		}
		L->length=L->length-k;
		return 1;
}

int DelReElem2(SqList *L){
		if(L->length<=1) return 0;
		int i=1;
		int k=1;
		while(i<L->length){
				if(L->data[i]!=L->data[i-1]){
						L->data[i]=L->data[k];
						k++;
				}
		}
		L->length=k;
		return 1;
}

int main(){
		return 0;
}
