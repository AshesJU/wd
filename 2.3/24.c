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

void tidy(LinkList *L,int n){
		int a[n],i,x;
		LNode *p=*L,*r;		
		for(i=0;i<n;i++) a[i]=0;
		while(p->next!=NULL){
				x=p->next->data<0?-p->next->data:p->next->data;
				if(a[x-1]==0){
						a[x-1]=1;
						p=p->next;
				}else{
						r=p->next;
						p->next=r->next;
						free(r);
				}
		}
}

int main(){
		LinkList L;
		int a[]={21,-15,-15,-7,15};
		createList(&L,a,5);
		show(L);
		tidy(&L,21);
		show(L);
		return 0;
}



