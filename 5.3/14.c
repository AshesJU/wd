#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 100

typedef struct BiTNode{
		int data;
		struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct{
		BiTree data[MaxSize];
		int front,rear;
}SqQueue;

void InitQueue(SqQueue *Q){
		Q->front=Q->rear=0;
}

bool EnQueue(SqQueue *Q,BiTree p){
		if((Q->rear+1)%MaxSize==Q->front) return false;
		Q->data[Q->rear]=p;
		Q->rear=(Q->rear+1)%MaxSize;
		return true;
}

bool DeQueue(SqQueue *Q,BiTree *p){
		if(Q->rear==Q->front) return false;
		*p=Q->data[Q->front];
		Q->front=(Q->front+1)%MaxSize;
		return true;
}

bool isEmpty(SqQueue Q){
		if(Q.rear==Q.front) return true;
		else return false;
}

int TreeWidth(BiTree T){
		if(!T) return 0;
		SqQueue Q1,Q2;
		BiTree p;
		int i,w=0;
		InitQueue(&Q1);
		InitQueue(&Q2);
		EnQueue(&Q1,T);
		while(!isEmpty(Q1)||!isEmpty(Q2)){				
				i=0;
				if(!isEmpty(Q1)){
						while(!isEmpty(Q1)){
								DeQueue(&Q1,&p);
								i++;
								if(p->lchild) EnQueue(&Q2,p->lchild);
								if(p->rchild) EnQueue(&Q2,p->rchild);
						}
				}else{
						while(!isEmpty(Q2)){
								DeQueue(&Q2,&p);
								i++;
								if(p->lchild) EnQueue(&Q1,p->lchild);
								if(p->rchild) EnQueue(&Q1,p->rchild);
						}
				}
				if(i>w) w=i;
		}
		return w;
}

int main(){
		BiTree T=(BiTNode*)malloc(sizeof(BiTNode));
		BiTNode *n2=(BiTNode*)malloc(sizeof(BiTNode));
		BiTNode *n3=(BiTNode*)malloc(sizeof(BiTNode));
		BiTNode *n4=(BiTNode*)malloc(sizeof(BiTNode));
		BiTNode *n5=(BiTNode*)malloc(sizeof(BiTNode));
		BiTNode *n6=(BiTNode*)malloc(sizeof(BiTNode));
		BiTNode *n7=(BiTNode*)malloc(sizeof(BiTNode));
		BiTNode *n8=(BiTNode*)malloc(sizeof(BiTNode));
		T->lchild=n2;
		T->rchild=n3;
		n2->lchild=n4;
		n2->rchild=n5;
		n3->lchild=n6;
		n3->rchild=n7;
		n4->lchild=n8;
		n4->rchild=NULL;
		n5->lchild=NULL;
		n5->rchild=NULL;
		n6->lchild=NULL;
		n6->rchild=NULL;
		n7->lchild=NULL;
		n7->rchild=NULL;
		n8->lchild=NULL;
		n8->rchild=NULL;
		printf("TreeWidth:%d\n",TreeWidth(T));
		return 0;
}
	
