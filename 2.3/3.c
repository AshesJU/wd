#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

void List_R(LinkList L){		
		if(L->next!=NULL){
				List_R(L->next);
				printf("%d\n",L->next->data);
		}
}

LinkList List_TailInsert(LinkList *L){
		LNode *s,*r;
		int i;
		*L=(LNode*)malloc(sizeof(LNode));
		(*L)->next=NULL;
		r=*L;
		scanf("%d",&i);
		while(i!=9999){
				s=(LNode*)malloc(sizeof(LNode));
				s->data=i;
				r->next=s;
				r=r->next;
				scanf("%d",&i);
		}
		r->next=NULL;
		return *L;
		
}

int main(){
		LinkList L;
		List_TailInsert(&L);
		List_R(L);
		return 0;
}
