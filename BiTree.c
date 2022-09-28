#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BiTNode{
		int data;
		struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct LinkNode{
		BiTNode *data;
		struct LinkNode *next;
}LinkNode;

typedef struct{
		LinkNode *front,*rear;
}LinkQueue;

void InitQueue(LinkQueue *Q){
		Q->rear=Q->front=(LinkNode*)malloc(sizeof(LinkNode));
		Q->front->next=NULL;
}

bool isEmpty(LinkQueue Q){
		if(Q.rear==Q.front) return true;
		else return false;
}

void EnQueue(LinkQueue *Q,BiTNode *tnode){
		LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
		s->data=tnode;
		s->next=NULL;
		Q->rear->next=s;
		Q->rear=s;
}

bool DeQueue(LinkQueue *Q,BiTNode **tnode){
		if(Q->front==Q->rear){
				printf("Empty Queue\n");
				return false;
		}
		LinkNode *p=Q->front->next;
		(*tnode)=p->data;
		Q->front->next=p->next;
		if(Q->rear==p){
				Q->rear=Q->front;
		}
		free(p);
		return true;
}

void visit(BiTNode *p){
		printf("%d ",p->data);
}

void PreOrder(BiTree T){
		if(T!=NULL){
				visit(T);
				PreOrder(T->lchild);
				PreOrder(T->rchild);
		}
}

void InOrder(BiTree T){
		if(T!=NULL){
				InOrder(T->lchild);
				visit(T);
				InOrder(T->rchild);
		}
}

void PostOrder(BiTree T){
		if(T!=NULL){
				PostOrder(T->lchild);
				PostOrder(T->rchild);
				visit(T);
		}
}

void LevelOrder(BiTree T){
		LinkQueue Q;
		BiTNode *p;
		InitQueue(&Q);
		EnQueue(&Q,T);
		while(!isEmpty(Q)){
				DeQueue(&Q,&p);
				visit(p);
				if(p->lchild!=NULL)
						EnQueue(&Q,p->lchild);
				if(p->rchild!=NULL)
						EnQueue(&Q,p->rchild);
		}
}

int treeDepth(BiTree T){
		if(T==NULL){
				return 0;
		}else{
				int l=treeDepth(T->lchild);
				int r=treeDepth(T->rchild);
				return l>r?l+1:r+1;
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
		printf("PreOrder    ");
		PreOrder(T);
		printf("\n");
		printf("InOrder     ");
		InOrder(T);
		printf("\n");
		printf("PostOrder   ");
		PostOrder(T);		
		printf("\n");
		printf("LevelOrder  ");
		LevelOrder(T);
		printf("\n");
		printf("TreeDepth:%d\n",treeDepth(T));
		
		return 0;
}
