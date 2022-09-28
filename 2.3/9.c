#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

void Order_Del(LinkList *L){
		LNode *p,*pre;
		while((*L)->next!=NULL){
				p=(*L)->next;
				pre=*L;
				while(p->next!=NULL){
						if(p->next->data<pre->next->data){
							pre=p;	
						}
						p=p->next;
				}
				p=pre->next;
				printf("%d\n",p->data);
				pre->next=pre->next->next;
				free(p);
		}
		free(*L);
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
		LinkList L=(LNode*)malloc(sizeof(LNode));
		int a[]={7,3,2,8,6,1};
		createList(&L,a,6);
		show(L);
		printf("\n");
		Order_Del(&L);
		return 0;

}
