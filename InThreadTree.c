#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct ThreadNode{
		int data;
		struct ThreadNode *lchild,*rchild;
		int ltag,rtag;
}ThreadNode,*ThreadTree;

void InThread(ThreadNode **p,ThreadNode **pre){
		if((*p)!=NULL){
				InThread(&((*p)->lchild),pre);
				if((*p)->lchild==NULL){
						(*p)->lchild=*pre;
						(*p)->ltag=1;
				}
				if(*pre&&(*pre)->rchild==NULL){
						(*pre)->rchild=*p;
						(*pre)->rtag=1;
				}
				*pre=*p;
				InThread(&((*p)->rchild),pre);	
		}
}

void CreateInThread(ThreadTree *T){
		ThreadNode *pre=NULL;
		if((*T)!=NULL){
				InThread(T,&pre);
				pre->rchild=NULL;
				pre->rtag=1;
		}
}

ThreadNode *FirstNode(ThreadNode *p){
		while(p->ltag==0){
				p=p->lchild;
		}
		return p;
}

ThreadNode *NextNode(ThreadNode *p){
		if(p->rtag==1){
				return p->rchild;
		}else{
				return FirstNode(p->rchild);
		}
}

ThreadNode *LastNode(ThreadNode *p){
		while(p->rtag==0){
				p=p->rchild;
		}
		return p;
}

ThreadNode *PreNode(ThreadNode *p){
		if(p->ltag==1){
				return p->lchild;
		}else{
				return LastNode(p->lchild);
		}
}

void visit(ThreadNode *p){
		printf("%d ",p->data);
}

void InOrder(ThreadTree T){
		ThreadNode *p=FirstNode(T);
		while(p!=NULL){
				visit(p);
				p=NextNode(p);
		}
}

void ReverseInOrder(ThreadTree T){
		ThreadNode *p=LastNode(T);
		while(p!=NULL){
				visit(p);
				p=PreNode(p);
		}
}

void InitThreadNode(ThreadTree *p){
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

		CreateInThread(&A);
		printf("InOrder ");
	    InOrder(A);
		printf("\n");
		printf("Reverse ");
		ReverseInOrder(A);
		printf("\n");
		return 0;
}

