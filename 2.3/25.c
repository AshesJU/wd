#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

void show(LinkList L){
		if(L==NULL) return;
		LNode *p=L->next;
		printf("Head->");
		while(p!=NULL){
				printf("%d->",p->data);
				p=p->next;
		}
		printf("NULL\n");
}

void createList(LinkList *L,int a[],int n){
		LNode *p,*s;
		*L=(LNode*)malloc(sizeof(LNode));
		(*L)->next=NULL;
		p=*L;
		int i;
		for(i=0;i<n;i++){
				s=(LNode*)malloc(sizeof(LNode));
				s->data=a[i];
				p->next=s;
				p=p->next;
		}
		p->next=NULL;
}

void change_list(LinkList *L){
		LNode *p=*L,*q=*L,*r,*s;
		while(q->next){
				p=p->next;
				q=q->next;
				if(q->next) q=q->next;
		}
		q=p->next;
		p->next=NULL;
		while(q){
				r=q->next;
				q->next=p->next;
				p->next=q;
				q=r;
		}
		s=(*L)->next;
		q=p->next;
		p->next=NULL;
		while(q){
				r=q->next;
				q->next=s->next;
				s->next=q;
				s=q->next;
				q=r;
		}
}

int main(){
		LinkList L;
		int a[]={1,2,3,4,5,6,7,8,9,10};
		createList(&L,a,10);
		show(L);
		change_list(&L);
		show(L);
		return 0;
}
