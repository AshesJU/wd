#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50

typedef struct BiTNode{
		int data;
		struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//递归方法:
void SwapChild(BiTree *B){
		BiTree p;
		if(*B){
				p=(*B)->lchild;
				(*B)->lchild=(*B)->rchild;
				(*B)->rchild=p;
				SwapChild(&((*B)->lchild));
				SwapChild(&((*B)->rchild));
		}
}

//非递归方法:
void SwapChild2(BiTree *B){
		BiTree Q[MaxSize];
		BiTree p,t;
		int front=0,rear=0;
		Q[rear]=*B;
		rear=(rear+1)%MaxSize;
		while(front!=rear){
				p=Q[front];
				front=(front+1)%MaxSize;
				t=p->lchild;
				p->lchild=p->rchild;
				p->rchild=t;
				if(p->lchild){
						Q[rear]=p->lchild;
						rear=(rear+1)%MaxSize;
				}
				if(p->rchild){
						Q[rear]=p->rchild;
						rear=(rear+1)%MaxSize;
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

void LevelOrder(BiTree T){
		BiTree Q[MaxSize],p;
		int front=0,rear=0;
		Q[rear]=T;
		rear=(rear+1)%MaxSize;
		while(front!=rear){
				p=Q[front];
				printf("%d ",p->data);
				front=(front+1)%MaxSize;
				if(p->lchild){
						Q[rear]=p->lchild;
						rear=(rear+1)%MaxSize;
				}
				if(p->rchild){
						Q[rear]=p->rchild;
						rear=(rear+1)%MaxSize;
				}
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
		LevelOrder(T);
		printf("\n");
		SwapChild2(&T);
		LevelOrder(T);
		printf("\n");
		return 0;
}

