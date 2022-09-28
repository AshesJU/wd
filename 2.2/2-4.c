#include<stdio.h>
#include<stdbool.h>

typedef struct{
		int data[10];
		int length;
}SqList;

bool del_s_t(SqList *L,int s,int t){
		int i,j;
		if(L->length==0||s>=t) return false;
		for(i=0;i<L->length&&L->data[i]>=s;i++);
		for(j=0;j<L->length&&L->data[j]<=t;j--);
		for(;j<L->length;j++,i++){		
				L->data[i]=L->data[j];
		}
		L->length=i;
		return true;
}

int main(){
		return 0;
}
