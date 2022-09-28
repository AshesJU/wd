#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

void delete_x(LinkList *L,int x){
		LNode *p=*L;
		LNode *temp;
		while(p->next!=NULL){
				if(p->next->data==x){
						temp=p->next;
						p->next=p->next->next;
						free(temp);
				}else{
						p=p->next;
				}
		}

}

show(LinkList L){
		LNode *p=L->next;
		while(p!=NULL){
				printf("%d\n",p->data);
				p=p->next;
		}

}


int main(){
		LinkList L;
		LNode *a,*b,*c;
		L=(LinkList)malloc(sizeof(LNode));
		a=(LNode*)malloc(sizeof(LNode));
		b=(LNode*)malloc(sizeof(LNode));
		c=(LNode*)malloc(sizeof(LNode));
		L->next=a;
		a->data=1;a->next=b;
		b->data=2;b->next=c;
		c->data=3;c->next=NULL;
		show(L);
		delete_x(&L,1);
		show(L);
		return 0;

}
