#include<stdio.h>
#include<stdbool.h>
#define MaxSize 20

typedef struct{
		int data[MaxSize];
		int front,rear;
}SqQueue;

void InitQueue(SqQueue *Q){
		Q->front=Q->rear=0;
}

bool isEmpty(SqQueue Q){
		if(Q.front==Q.rear) return true;
		else return false;
}

bool EnQueue(SqQueue *Q,int x){
		if((Q->rear+1)%MaxSize==Q->front) return false;
		Q->data[Q->rear]=x;
		Q->rear=(Q->rear+1)%MaxSize;
		return true;								   
}

bool DeQueue(SqQueue *Q,int *x){
		if(Q->front==Q->rear) return false;
		*x=Q->data[Q->front];
		Q->front=(Q->front+1)%MaxSize;
		return true;
}

