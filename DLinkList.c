#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct DNode{
		int data;
		struct DNode *next;
		struct DNode *prior;
}DNode,*DLinkList;

bool InitDLinkList(DLinkList *L){
		*L=(DNode*)malloc(sizeof(DNode));
		if(*L==NULL) return false;
		(*L)->next=NULL;
		(*L)->prior=NULL;
		return true;
}

bool InsertNextDNode(DNode *p,DNode *s){
		if(p==NULL||s==NULL) return false;
		s->prior=p;		
		s->next=p->next;
		if(p->next!=NULL){
				p->next->prior=s;
		}
		p->next=s;
		return true;
}

bool DeleteNextDNode(DNode *p){
		if(p==NULL) return false;
		DNode *q=p->next;
		if(q==NULL) return false;
		p->next=q->next;
		if(q->next!=NULL){
				q->next->prior=p;
		}
		free(q);
		return true;
}

void showList(DLinkList L){
		DNode *p=L->next;
		while(p!=NULL){
				printf("%d\n",p->data);
				p=p->next;
		}
}

int main(){
		DLinkList L;
		InitDLinkList(&L);
		DNode *p=(DNode*)malloc(sizeof(DNode));
		DNode *s=(DNode*)malloc(sizeof(DNode));
		p->data=1;
		s->data=2;
		InsertNextDNode(L,s);
		InsertNextDNode(L,p);
		showList(L);
		DeleteNextDNode(p);
		showList(L);
		return 0;
}

