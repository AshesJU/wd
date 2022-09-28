#include<stdio.h>
#include<stdbool.h>

typedef struct{
		int data[10];
		int length;
}SqList;

bool del_s_t_1(SqList *L,int s,int t){
		if(L->length==0||s>=t) return false;
		int i=0;
		int k=0;
		while(i<L->length){
				if(L->data[i]>t&&L->data[i]<s){
						L->                     data[k]=L->data[i];
				}
				i++;
		}
		L->length=k;
}

bool del_s_t_2(SqList *L,int s,int t){
		if(s>=t||L->length==0) return false;
		int i;
		int k=0;
		for(i=0;i<L->length;i++){
				if(L->data[i]>=s&&L->data[i]<=t)
						k++;
				else
						L->data[i-k]=L->data[i];
		}
		L->length=L->length-k;
		return true;

}

int main(){
		return 0;
}	
