#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

typedef struct{
		LNode *front,*rear;
}LinkQueue;

void InitQueue(LinkQueue *Q){
		Q->front=Q->rear=(LNode*)malloc(sizeof(LNode));
		Q->front->next=NULL;
}

bool isEmpty(LinkQueue Q){
		if(Q.front==Q.rear) return true;
		else return false;
}

void EnQueue(LinkQueue *Q,int x){
		LNode *s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=NULL;
		Q->rear->next=s;
		Q->rear=s;
		printf("EnQueue %d\n",x);
}

bool DeQueue(LinkQueue *Q,int *x){
		if(Q->front==Q->rear){
				printf("Fail to DeQueue,Empty Queue.\n");
				return false;
		}		
		LNode *p=Q->front->next;
		*x=p->data;
		Q->front->next=p->next;
		if(p==Q->rear) Q->rear=Q->front;
		free(p);
		printf("DeQueue %d\n",*x);
		return true;
}

int main(){
		LinkQueue Q;
		int x;
		InitQueue(&Q);
		if(isEmpty(Q)) printf("Empty Queue\n");
		EnQueue(&Q,1);
		EnQueue(&Q,2);
		EnQueue(&Q,3);
		DeQueue(&Q,&x);
		DeQueue(&Q,&x);
		DeQueue(&Q,&x);
		DeQueue(&Q,&x);
		return 0;
}
