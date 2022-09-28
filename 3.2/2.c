#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 5

typedef struct{
		int data[MaxSize];
		int front,rear;
}SqQueue;

typedef struct{
		int data[MaxSize];
		int top;
}SqStack;

void InitQueue(SqQueue *Q){
		Q->front=0;
		Q->rear=0;
}

bool isEmpty(SqQueue Q){
		if(Q.front==Q.rear) return true;
		else return false;
}

bool EnQueue(SqQueue *Q,int x){
		if((Q->rear+1)%MaxSize==Q->front){
				printf("Queue is full.\n");
				return false;
		}
		Q->data[Q->rear]=x;
		printf("EnQueue %d\n",x);
		Q->rear=(Q->rear+1)%MaxSize;
		return true;
}

bool DeQueue(SqQueue *Q,int *x){
		if(Q->front==Q->rear){
				printf("Queue empty.\n");
				return false;
		}
		*x=Q->data[Q->front];
		printf("DeQueue %d\n",*x);
		Q->front=(Q->front+1)%MaxSize;
		return true;
}

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

void reverse(SqQueue *Q,SqStack *S){
		int x;
		while(!isEmpty(*Q)){
				DeQueue(Q,&x);
				Push(S,x);
		}
		while(!StackEmpty(*S)){
				Pop(S,&x);
				EnQueue(Q,x);
		}
}

int main(){
		SqStack S;
		SqQueue Q;
		InitStack(&S);
		InitQueue(&Q);
		EnQueue(&Q,1);
		EnQueue(&Q,2);
		EnQueue(&Q,3);
		EnQueue(&Q,4);
		reverse(&Q,&S);
		return 0;
}
