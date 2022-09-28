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
		if(S->top==MaxSize) return false;
		S->data[++S->top]=p;
		return true;
}

bool pop(SqStack *S,BiTree *p){
		if(S->top==-1) return false;
		*p=S->data[S->top--];
		return true;
}

//答案方法
int PreNode(BiTree T,int k,int *i){
		int j;
		if(T==NULL){
				return -1;
		}else if(*i==k){
				return T->data;
		}else{
				(*i)++;
				j=PreNode(T->lchild,k,i);
				if(j!=-1){
						return j;
				}else{
						j=PreNode(T->rchild,k,i);
						return j;
				}
		}
		
}

//递归方法
void PreOrder(BiTree T,int *i,int k){
		if(*i==k){
				printf("%d--%d\n",k,T->data);
		}else{
				if(T->lchild){
						(*i)++;
						PreOrder(T->lchild,i,k);
				}
				if(T->rchild){
						(*i)++;
						PreOrder(T->rchild,i,k);
				}
		}
}

void PreOrder_k(BiTree T,int k){
		if(!T) return;
		int i=1;
		PreOrder(T,&i,k);
}

//非递归方法
int PreOrder2(BiTree T,int k){
		SqStack S;
		InitStack(&S);
		BiTree p=T;
		int i=0;
		while(p||!isEmpty(S)){
				if(p){
						push(&S,p);
						p=p->lchild;
				}else{
						pop(&S,&p);
						if(++i==k){
								printf("%d",p->data);
								return 1;
						}
						p=p->rchild;
				}
		}
		return 0;
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
		int t=1;
		for(int i=1;i<=8;i++){
				printf("%d\n",PreNode(T,i,&t));
		}
		return 0;
}
