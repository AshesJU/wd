#include<stdio.h>
#include<stdlib.h>

typedef struct DNode{
		int data;
		struct DNode *prior;
		struct DNode *next;
}DNode,*DLinkList;

int symmetry(DLinkList L){
		DNode *p=L->next,*q=L->prior;
		while(p!=q&&p->prior!=q){
				if(p->data==q->data){
						p=p->next;
						q=q->prior;
				}else return 0;
		}
		return 1;
}

void createDList(DLinkList *L,int a[],int n){
		int i;
		*L=(DNode*)malloc(sizeof(DNode));
		(*L)->next=NULL;
		(*L)->prior=NULL;
		DNode *s,*pre=*L;
		for(i=0;i<n;i++){
				s=(DNode*)malloc(sizeof(DNode));
				s->data=a[i];
				s->prior=pre;
				pre->next=s;
				pre=pre->next;
		}
		pre->next=*L;
		(*L)->prior=pre;
}

void show(DLinkList L){
		DNode *p=L->next;
		printf("L<->");
		while(p!=NULL&&p!=L){
				printf("%d<->",p->data);
				p=p->next;
		}
		printf("L\n");
}

int main(){
		DLinkList L;
		int a[]={1,2,3,4,3,2,1};
		createDList(&L,a,7);
		show(L);
		if(symmetry(L)) printf("symmetry\n");
		else printf("asymmetry\n");
		return 0;
}
