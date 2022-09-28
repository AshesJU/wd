#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode{
		int data;
		struct LNode *next; 
}LNode,*LinkList;

bool reverse(LinkList *L){
		LNode *left,*p,*right;
		if(*L==NULL) return false;
		if((*L)->next==NULL) return false;
		left=*L;
		p=left->next;
		right=p->next;
		while(p->next!=NULL){
				p->next=left;
				left=p;
				p=right;
				right=right->next;
		}
		(*L)->next->next=NULL;
		(*L)->next=p;
		if(left!=*L) p->next=left;
		return true;
		
}

bool reverse1(LinkList *L){
		LNode *p,*r;
		if(*L==NULL) return false;
		p=(*L)->next;
		(*L)->next=NULL;
		while(p!=NULL){
				r=p->next;
				p->next=(*L)->next;
				(*L)->next=p;
				p=r;
		}
		return true;
}

bool reverse2(LinkList *L){
		LNode *pre,*p,*r;
		if(*L==NULL) return false;
		p=(*L)->next;
		r=p->next;
		p->next=NULL;
		while(r!=NULL){
				pre=p;
				p=r;
				r=r->next;
				p->next=pre;
		}
		(*L)->next=p;
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
		reverse(&L);
		List(L);
		return 0;
}
