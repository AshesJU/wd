#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

 LNode* CommonSuffixStart(LNode *str1,LNode *str2){
		 int l1=0,l2=0,c,i;
		 LNode *p1=str1,*p2=str2;
		 while(p1->next){
				 l1++;
				 p1=p1->next;
		 }
		 while(p2->next){
				 l2++;
				 p2=p2->next;
		 }
		 p1=str1;
		 p2=str2;
		 if(l1>l2){
				 c=l1-l2;
				 for(i=0;i<c;i++){
						 p1=p1->next;
				 }
		 }else{
				 c=l2-l1;
				 for(i=0;i<c;i++){
						 p2=p2->next;
				 }
		 }
		 
		 while(p1->next!=NULL){
				 p1=p1->next;
				 p2=p2->next;
				 if(p1==p2) return p1;
		 }
		 return NULL;
}

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

int main(){
		LinkList str1,str2;
		LNode *a,*b,*c,*d,*e,*f,*g,*p;
		str1=(LNode*)malloc(sizeof(LNode));
		str2=(LNode*)malloc(sizeof(LNode));
		a=(LNode*)malloc(sizeof(LNode));
		b=(LNode*)malloc(sizeof(LNode));
		c=(LNode*)malloc(sizeof(LNode));
		d=(LNode*)malloc(sizeof(LNode));
		e=(LNode*)malloc(sizeof(LNode));
		f=(LNode*)malloc(sizeof(LNode));
		g=(LNode*)malloc(sizeof(LNode));
		str1->next=a;
		a->next=b;a->data=1;
		b->next=c;b->data=2;
		c->next=d;c->data=3;
		d->next=e;d->data=4;
		e->next=f;e->data=5;
		str2->next=g;f->data=6;
		g->next=f;g->data=7;
		
		p=CommonSuffixStart(str1,str2);
		if(p!=NULL) printf("Common:%d\n",p->data);
		else printf("No common suffix\n");
		return 0;
}
