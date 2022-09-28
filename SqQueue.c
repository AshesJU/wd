#include<stdio.h>
#include<stdbool.h>

#define MaxSize 4

typedef struct{
		int data[MaxSize];
		int front,rear;
}SqQueue;

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

int main(){
		SqQueue Q;
		int x;
		InitQueue(&Q);
		if(isEmpty(Q)) printf("Empty Queue\n");
		EnQueue(&Q,1);
		EnQueue(&Q,2);
		EnQueue(&Q,3);
		EnQueue(&Q,4);
		DeQueue(&Q,&x);
		DeQueue(&Q,&x);
		DeQueue(&Q,&x);
		DeQueue(&Q,&x);
		return 0;
}
