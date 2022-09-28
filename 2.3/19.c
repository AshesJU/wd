#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

void delete(LinkList *L){
		LNode *pre,*p,*mp,*mpre;
		while((*L)->next!=*L){
				p=(*L)->next;
				pre=*L;
				mpre=*L;
				mp=p;
				while(p!=*L){
						if(p->data<mp->data){
								mpre=pre;
								mp=p;
						}
						p=p->next;
						pre=pre->next;
				}
				mpre->next=mp->next;
				printf("%d\n",mp->data);
				free(mp);
		}
		free(*L);
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
		int a[]={7,4,9,2,1,3,8};
		createList(&A,a,7);
		show(A);
		delete(&A);
		return 0;
}

