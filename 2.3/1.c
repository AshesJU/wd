#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

void Delete_x(LinkList *L,int x){
		LNode *p;
		if(*L==NULL) return;
		if(p->data==x){
				p=L;
				*L=(*L)->next;
				free(p);
				Delete_x(L,x);
		}else{
				Delete_x(&((*L)->next),x);
		}

}

void show(LinkList L){
		LNode *p=L;
		while(p!=NULL){
				printf("%d\n",p->data);
				p=p->next;
		}
}

int main(){
		LNode *a,*b,*c;
		a=(LNode*)malloc(sizeof(LNode));
		b=(LNode*)malloc(sizeof(LNode));
		c=(LNode*)malloc(sizeof(LNode));
		a->data=1;a->next=b;
		b->data=2;b->next=c;
		c->data=3;c->next=NULL;
		show(a);
		Delete_x(&a,1);
		show(a);
		return 0;
}
