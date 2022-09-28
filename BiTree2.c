#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BiTNode{
		int data;
		struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct LNode{
		BiTNode *tnode;
		struct LNode *next;
}LNode,*LinkStack;

void InitStack(LinkStack *S){
		*S=(LNode*)malloc(sizeof(LNode));
		(*S)->next=NULL;
}

void Push(LinkStack *S,BiTNode *p){
		LNode *s=(LNode*)malloc(sizeof(LNode));
		s->tnode=p;
		s->next=(*S)->next;
		(*S)->next=s;
}

bool Pop(LinkStack *S,BiTNode **p){
		if((*S)->next==NULL) return false;
		*p=(*S)->next->tnode;
		LNode *q=(*S)->next;
		(*S)->next=q->next;
		free(q);
		return true;
}

bool isEmpty(LinkStack S){
		if(S->next!=NULL) return false;
		else return true;
}

void visit(BiTNode *p){
		printf("%d ",p->data);
}

void InOrder2(BiTree T){
		LinkStack S;
		InitStack(&S);
		BiTNode *p=T;
		while(p||!isEmpty(S)){
				if(p){
						Push(&S,p);
						p=p->lchild;
				}else{
						Pop(&S,&p);
						visit(p);
						p=p->rchild;
				}
		}

}

void PreOrder2(BiTree T){
		LinkStack S;
		InitStack(&S);
		BiTNode *p=T;
		while(p||!isEmpty(S)){
				if(p){
						visit(p);
						Push(&S,p);
						p=p->lchild;
				}else{
						Pop(&S,&p);
						p=p->rchild;
				}
		}
}

void PostOrder2(BiTree T){
		LinkStack S;
		InitStack(&S);
		BiTree p=T,r=NULL;
		while(p||!isEmpty(S)){
				if(p){
						Push(&S,p);
						p=p->lchild;
				}else{
						p=S->next->tnode;
						if(p->rchild&&p->rchild!=r){
								p=p->rchild;
						}else{
								Pop(&S,&p);
								r=p;
								visit(p);
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
		printf("InOrder   ");
		InOrder2(T);
		printf("\n");
		printf("PreOrder  ");
		PreOrder2(T);
		printf("\n");
		printf("PostOrder ");
		PostOrder2(T);
		printf("\n");
		return 0;
}
