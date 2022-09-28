#include<stdio.h>
#include<stdlib.h>

typedef struct ThreadNode{
		int data;
		struct ThreadNode *lchild,*rchild;
		int ltag,rtag;
}ThreadNode,*ThreadTree;

void Thread(ThreadNode **p,ThreadNode **pre){
		if(*p!=NULL){
				if((*p)->lchild==NULL){
						(*p)->lchild=*pre;
						(*p)->ltag=1;
				}
				if(*pre!=NULL&&(*pre)->rchild==NULL){
						(*pre)->rchild=*p;
						(*pre)->rtag=1;
				}
				*pre=*p;
				if((*p)->ltag!=1)
						Thread(&((*p)->lchild),pre);
				Thread(&((*p)->rchild),pre);
		}
}

void CreatePreThread(ThreadTree *T){
		ThreadTree pre=NULL;
		if(T!=NULL){
				Thread(T,&pre);
				pre->rchild=NULL;
				pre->rtag=1;
		}
}

ThreadNode *NextNode(ThreadTree p){
		if(p->rtag==1){
				return p->rchild;
		}else{
				return p->lchild;
		}
		
}

void PreOrder(ThreadTree T){
		ThreadTree p=T;
		while(p!=NULL){
				printf("%d ",p->data);
				p=NextNode(p);
		}
		printf("\n");
}

void InitThreadNode(ThreadNode **p){
		(*p)->lchild=NULL;
		(*p)->rchild=NULL;
		(*p)->ltag=0;
		(*p)->rtag=0;
		(*p)->data=-1;
}

int main(){
		ThreadTree A=(ThreadNode*)malloc(sizeof(ThreadNode));
		ThreadTree B=(ThreadNode*)malloc(sizeof(ThreadNode));
		ThreadTree C=(ThreadNode*)malloc(sizeof(ThreadNode));
		ThreadTree D=(ThreadNode*)malloc(sizeof(ThreadNode));
		ThreadTree E=(ThreadNode*)malloc(sizeof(ThreadNode));
		ThreadTree F=(ThreadNode*)malloc(sizeof(ThreadNode));
		ThreadTree G=(ThreadNode*)malloc(sizeof(ThreadNode));
		InitThreadNode(&A);
		InitThreadNode(&B);
		InitThreadNode(&C);
		InitThreadNode(&D);
		InitThreadNode(&E);
		InitThreadNode(&F);
		InitThreadNode(&G);
		A->data=1;
		B->data=2;
		C->data=3;
		D->data=4;
		E->data=5;
		F->data=6;
		G->data=7;
		A->lchild=B;
		A->rchild=C;
		B->lchild=D;
		B->rchild=E;
		C->lchild=F;
		C->rchild=G;
		D->lchild=NULL;
		D->rchild=NULL;
		E->lchild=NULL;
		E->rchild=NULL;
		F->lchild=NULL;
		F->rchild=NULL;
		G->lchild=NULL;
		G->rchild=NULL;	
		CreatePreThread(&A);
		printf("PreOrder:");
		PreOrder(A);
		return 0;
}
