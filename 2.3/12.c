#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

void del_re(LinkList *L){
		if(*L==NULL) return;
		if((*L)->next==NULL) return;
		LNode *p=(*L)->next;
		LNode *t;
		while(p->next!=NULL){
				if(p->next->data==p->data){
						t=p->next;
						p->next=p->next->next;
						free(t);
				}else{
						p=p->next;
				}
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

int main(){
		LinkList L;
		int a[]={1,1,1,2,3,4,4,5,5};
		createList(&L,a,9);
		show(L);
		del_re(&L);
		printf("\n");
		show(L);
		return 0;
}
