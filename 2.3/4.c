#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

bool delete_min(LinkList *L){
		LNode *p,*m,*t;
		if(*L==NULL) return false;
		if((*L)->next==NULL) return false;
		p=(*L)->next;
		m=*L;
		while(p->next!=NULL){
				if(p->next->data<m->next->data){
						m=p;
				}
				p=p->next;
		}
		t=m->next;
		m->next=m->next->next;
		free(t);
		return true;
}

void List(LinkList L){
		if(L==NULL) return;
		LNode *p=L->next;
		while(p!=NULL){
				printf("%d\n",p->data);
				p=p->next;
		}
}

int main(){
		LinkList L=(LNode*)malloc(sizeof(LNode));
		LNode *a,*b,*c;
		a=(LNode*)malloc(sizeof(LNode));
		b=(LNode*)malloc(sizeof(LNode));
		c=(LNode*)malloc(sizeof(LNode));
		L->next=a;
		L->data=-1;
		a->next=b;
		a->data=3;
		b->next=c;
		b->data=2;
		c->next=NULL;
		c->data=1;
		List(L);
		delete_min(&L);
		List(L);
		return 0;
}
