#include<stdio.h>
#include<stdlib.h>

typedef struct ThreadNode{
		int data;
		struct ThreadNode *lchild,*rchild;
		int ltag,rtag;
}ThreadNode,*ThreadTree;

void Thread(ThreadTree *p,ThreadTree *pre){
		if((*p)!=NULL){
				Thread(&((*p)->lchild),pre);
				Thread(&((*p)->rchild),pre);
				if((*p)->lchild==NULL){
						(*p)->lchild=*pre;
						(*p)->ltag=1;
				}
				if((*pre)!=NULL&&(*pre)->rchild==NULL){
						(*pre)->rchild=*p;
						(*pre)->rtag=1;
				}
				*pre=*p;
		}
}

void CreatePostThread(ThreadTree *T){
		ThreadTree pre=NULL;
		if((*T)!=NULL){
				Thread(T,&pre);
				if(pre->rchild==NULL){
						pre->rtag=1;
				}
		}
}

ThreadTree PreNode(ThreadTree p){
		if(p->rchild!=NULL&&p->rtag==0){
				return p->rchild;
		}else{
				return p->lchild;
		}
}

void ReversePostOrder(ThreadTree T){
		while(T!=NULL){
				printf("%d ",T->data);
				T=PreNode(T);
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

		CreatePostThread(&A);
		printf("Reverse ");
		ReversePostOrder(A);
		printf("\n");
		return 0;
}
