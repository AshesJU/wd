#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20

typedef struct BiTNode{
		int data;
		struct BiTNode *lchild,*rchild;
}*BiTree,BiTNode;

int BTDepth(BiTree T){
		if(!T) return 0;
		BiTree Q[MaxSize];
		int last=0,level=0,front=-1,rear=-1;
		BiTNode *p;
		Q[++rear]=T;
		while(front!=rear){
				p=Q[++front];
				if(p->lchild){
						Q[++rear]=p->lchild;
				}
				if(p->rchild){
						Q[++rear]=p->rchild;
				}
				if(front==last){
						level++;
						last=rear;
				}
		}
		return level;
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
		T->data=1;
		n2->data=2;
		n3->data=3;
		n4->data=4;
		n5->data=5;
		n6->data=6;
		n7->data=7;
		n8->data=8;
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
		printf("TreeDepth:%d\n",BTDepth(T));
		return 0;
}
