#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 50
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

bool isEmpty(SqQueue Q){
		if(Q.front==Q.rear) return true;
		else return false;
}

bool EnQueue(SqQueue *Q,BiTree p){
		if((Q->rear+1)%MaxSize==Q->front) return false;
		Q->data[Q->rear]=p;
		Q->rear=(Q->rear+1)%MaxSize;
		return true;
}

bool DeQueue(SqQueue *Q,BiTree *p){
		if(isEmpty(*Q)) return false;
		*p=Q->data[Q->front];
		Q->front=(Q->front+1)%MaxSize;
		return true;
}

bool isComplete(BiTree T){
		BiTNode *p;
		SqQueue Q;
		InitQueue(&Q);
		EnQueue(&Q,T);
		while(!isEmpty(Q)){
				DeQueue(&Q,&p);
				if(p){
						EnQueue(&Q,p->lchild);
						EnQueue(&Q,p->rchild);
				}else{
						while(!isEmpty(Q)){
								DeQueue(&Q,&p);
								if(p) return false;
						}
				}
		}
		return true;
		
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
		if(isComplete(T)) printf("Complete Binary Tree!\n");
		else printf("Incomplete Binary Tree..\n");
		return 0;
		return 0;
}
