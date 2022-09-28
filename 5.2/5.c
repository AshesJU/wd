#include<stdio.h>
#include<stdbool.h>
#define MaxSize 10

typedef struct{
		int data[MaxSize];
}SqTree;


int commonAncestor(SqTree T,int i,int j){
		if(T.data[i]!=-1&&T.data[j]!=-1){
				while(i!=j){
						if(i<j){
								j=j/2;
						}else{
								i=i/2;
						}
				}
		}
		return T.data[i];
}

int main(){
		SqTree T;
		int i=0;
		int e[]={-1,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
		while(i<16){
				T.data[i]=e[i];
				i++;
		}
		printf("%d\n",commonAncestor(T,12,15));
		return 0;
}

