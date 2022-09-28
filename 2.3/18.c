#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

void merge(LinkList *h1,LinkList *h2){
		LNode *p=*h1,*q=*h2;
		while(p->next!=*h1){
				p=p->next;
		}
		while(q->next!=*h2){
				q=q->next;
		}
		p->next=*h2;
		q->next=*h1;
}

void show(LinkList L){
		if(L==NULL) return;
		LNode *p=L->next;
		printf("L->");
		while(p!=L){
				printf("%d->",p->data);
				p=p->next;
		}
		printf("L\n");
}

void createList(LinkList *L,int a[],int n){
		LNode *p,*s;
		*L=(LNode*)malloc(sizeof(LNode));
		(*L)->data=666;
		(*L)->next=NULL;
		p=*L;
		int i;
		for(i=0;i<n;i++){
				s=(LNode*)malloc(sizeof(LNode));
				s->data=a[i];
				p->next=s;
				p=p->next;
		}
		p->next=*L;
}

int main(){
		LinkList A,B;
		int a[]={1,2,3,2,3,4,5};
		int b[]={2,3,4};
		createList(&A,a,7);
		createList(&B,b,3);
		show(A);show(B);
		merge(&A,&B);
		show(A);
		return 0;
}

