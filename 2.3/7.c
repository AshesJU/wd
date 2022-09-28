#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

int delete_a_b(LinkList *L,int a,int b){
		if(*L==NULL) return -1;
		LNode *pre=*L;
		LNode *p=(*L)->next;
		while(p!=NULL){
				if(p->data>a&&p->data<b){
						pre->next=p->next;
						free(p);
						p=pre->next;
				}else{
						pre=p;
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
		L=(LNode*)malloc(sizeof(LNode));
		L->next=NULL;
		int A[10]={1,2,3,4,5,6,7,8,9,10};
		createList(&L,A,10);
		show(L);
		delete_a_b(&L,4,7);
		show(L);

		return 0;
}


