#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50

typedef struct BiTNode{
		int data;
		struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void DeleteXTree(BiTree *T){
		if(*T){
				DeleteXTree(&((*T)->lchild));
				DeleteXTree(&((*T)->rchild));
				free(*T);
		}
}

void SearchX(BiTree T,int x){
		BiTree Q[MaxSize],p;
		int front=0,rear=0;
		if(T->data==x){
				DeleteXTree(&T);
				exit(0);
		}
		Q[rear]=T;
		rear=(rear+1)%MaxSize;
		while(front!=rear){
				p=Q[front];
				front=(front+1)%MaxSize;
				if(p->lchild){
						if(p->lchild->data==x){
								DeleteXTree(&(p->lchild));
								p->lchild=NULL;
						}else{
								Q[rear]=p->lchild;
								rear=(rear+1)%MaxSize;
						}
				}
				if(p->rchild){
						if(p->rchild->data==x){
								DeleteXTree(&(p->rchild));
								p->rchild=NULL;
						}else{
								Q[rear]=p->rchild;
								rear=(rear+1)%MaxSize;
						}
				}
		}
}


void PreOrder(BiTree T){
		if(T){
				printf("%d ",T->data);
				PreOrder(T->lchild);
				PreOrder(T->rchild);
		}
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
		n3->data=666;
		n4->data=4;
		n5->data=666;
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
		PreOrder(T);
		printf("\n");
		SearchX(T,666);
		PreOrder(T);
		printf("\n");
		return 0;
}
