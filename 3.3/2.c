#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100

typedef struct{
		char data[MaxSize];
		int top;
}SqStack;

void Train_Arrange(char train[]){
		SqStack S;
		S.top=-1;
		char *p=train;
		int i=0;
		while(train[i]!='\0'){
				if(train[i]=='H'){
						S.data[++S.top]=train[i];
				}else{
						*p=train[i];	
						p++;
				}
				i++;
		}
		while(S.top!=-1){
				*(p++)=S.data[S.top--];
		}
}

int main(){
		char train[]="HHSHSSSHSHSHSS";
		Train_Arrange(train);
		printf("%s\n",train);
		return 0;
}
