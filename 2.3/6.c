#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

void sort(LinkList *L){
		LNode *pre,*p,*r;
		if(*L==NULL) return;
		if((*L)->next==NULL) return;
		p=(*L)->next;
		r=p->next;
		p->next=NULL;
		p=r;
		while(p!=NULL){
				r=r->next;
				pre=*L;
				while(pre->next!=NULL&&pre->next->data<p->data){
						pre=pre->next;
				}
				p->next=pre->next;
				pre->next=p;
				p=r;
		}
}

void show(LinkList L){
		if(L==NULL) return;
		LNode *p=L->next;
		while(p!=NULL){
				printf("%d\n",p->data);
				p=p->next;
		}
}

void createList(LinkList *L,int a[],int n){
		LNode *p=*L,*s;
		int i;
		for(i=0;i<n;i++){
				s=(LNode*)malloc(sizeof(LNode));
				s->data=a[i];
				p->next=s;
				p=p->next;
		}
		p->next=NULL;
}

int main(){
	LinkList L;
	int a[]={7,3,6,1,10,5};
	L=(LNode*)malloc(sizeof(LNode));
	L->next=NULL;
	createList(&L,a,6);
	show(L);
	sort(&L);
	show(L);
	return 0;
}
