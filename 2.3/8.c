#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

int length(LinkList L){
		int i=0;
		LNode *p=L;
		while(p->next!=NULL){
				p=p->next;
				i++;
		}
		return i;
}

LNode* CommonNode(LinkList A,LinkList B){
		int i,j,l;
		int la=length(A);
		int lb=length(B);
		LNode *longlist,*shortlist;
		if(la>lb){
				longlist=A;
				shortlist=B;
				l=la-lb;
		}else{
				longlist=B;
				shortlist=A;
				l=lb-la;
		}
		for(i=0;i<l;i++){
				longlist=longlist->next;
		}
		while(longlist!=NULL){
				if(longlist==shortlist) return longlist;
				longlist=longlist->next;
				shortlist=shortlist->next;
		}
		return NULL;
}



void show(LinkList L){
		if(L==NULL) return;
		LNode *p=L->next;
		while(p!=NULL){
				printf("%d\n",p->data);
				p=p->next;
		}
}
int main(){
		LinkList L1,L2;
		L1=(LNode*)malloc(sizeof(LNode));
		L2=(LNode*)malloc(sizeof(LNode));
		LNode *a,*b,*c,*d,*e,*f;
		a=(LNode*)malloc(sizeof(LNode));
		b=(LNode*)malloc(sizeof(LNode));
		c=(LNode*)malloc(sizeof(LNode));
		d=(LNode*)malloc(sizeof(LNode));
		e=(LNode*)malloc(sizeof(LNode));
		f=(LNode*)malloc(sizeof(LNode));
		L1->next=a;a->next=e;e->next=f;f->next=NULL;
		L2->next=b;b->next=c;c->next=d;d->next=e;
		a->data=1;b->data=2;c->data=3;d->data=4;e->data=5;f->data=6;
		printf("L1:\n");show(L1);
		printf("L2:\n");show(L2);
		LNode *common=CommonNode(L1,L2);
		printf("common:%d\n",common->data);
		return 0;	
		
}
