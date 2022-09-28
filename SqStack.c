#include<stdio.h>
#include<stdbool.h>
#define MaxSize 50

typedef struct{
		int data[MaxSize];
		int top;
}SqStack;

void InitStack(SqStack *S){
		S->top=-1;
}

bool StackEmpty(SqStack S){
		if(S.top==-1) return true;
		return false;
}

bool Push(SqStack *S,int x){
		if(S->top==MaxSize-1) return false;
		S->data[++S->top]=x;
		return true;
}

bool Pop(SqStack *S,int *x){
		if(S->top==-1) return false;
		*x=S->data[S->top--];
		return true;
}

bool GetTop(SqStack S,int *x){
		if(S.top==-1) return false;
		*x=S.data[S.top];
		return true;
}

int main(){
		SqStack S;
		int e;
		InitStack(&S);
		if(StackEmpty) printf("Empty stack\n");
		Push(&S,1);
		Push(&S,2);
		GetTop(S,&e);
		printf("Top element:%d\n",e);
		Pop(&S,&e);
		printf("Pop %d\n",e);
		GetTop(S,&e);
		printf("Top element:%d\n",e);
		Pop(&S,&e);
		printf("Pop %d\n",e);
		if(!Pop(&S,&e)) printf("Pop fail\n");
		return 0;
}
