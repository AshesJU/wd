#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 3

typedef struct{
		int data[MaxSize];
		int front,rear,tag;
}SqQueue;

void InitQueue(SqQueue *Q){
		Q->front=Q->rear=0;
		Q->tag=0;
}

bool EnQueue(SqQueue *Q,int x){
		if(Q->front==Q->rear&&Q->tag==1) return false;
		Q->data[Q->rear]=x;
		Q->rear=(Q->rear+1)%MaxSize;
		Q->tag=1;
		return true; 
}

bool DeQueue(SqQueue *Q,int *x){
		if(Q->front==Q->rear&&Q->tag==0) return false;
		*x=Q->data[Q->front];
		Q->front=(Q->front+1)%MaxSize;
		Q->tag=0;
		return true; 
}

int main(){
		SqQueue Q;
		int x;
		InitQueue(&Q);
		if(EnQueue(&Q,1)) printf("EnQueue\n");
		if(EnQueue(&Q,1)) printf("EnQueue\n");
		if(EnQueue(&Q,1)) printf("EnQueue\n");
		if(EnQueue(&Q,1)) printf("EnQueue\n");
		if(DeQueue(&Q,&x)) printf("DeQueue\n");
		if(DeQueue(&Q,&x)) printf("DeQueue\n");
		if(DeQueue(&Q,&x)) printf("DeQueue\n");
		if(DeQueue(&Q,&x)) printf("DeQueue\n");
		return 0;
}
