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
		int top;
}SqStack;

void InitStack(SqStack *S){
		S->top=-1;
}

bool isEmpty(SqStack S){
		if(S.top==-1) return true;
		else return false;
}

bool push(SqStack *S,BiTree p){
		if(S->top==MaxSize-1) return false;
		S->data[++S->top]=p;
		return true;
}

bool pop(SqStack *S,BiTree *p){
		if(S->top==-1) return false;
		*p=S->data[S->top--];
		return true;
}

void Search(BiTree T,int x){
		SqStack S;
		InitStack(&S);
		BiTree p=T,r=NULL;
		while(p||!isEmpty(S)){
				if(p){
						push(&S,p);
						p=p->lchild;
				}else{
						p=S.data[S.top];
						if(p->rchild&&p->rchild!=r){
								p=p->rchild;
						}else{
								pop(&S,&p);
								if(p->data==x){
										while(!isEmpty(S)){
										pop(&S,&p);
										printf("%d\n",p->data);
										}
										exit(0);
								}
								r=p;
								p=NULL;
						}
						
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
		Search(T,8);
		return 0;
}

