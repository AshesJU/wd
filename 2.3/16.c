#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

int length(LinkList L){
		LNode *p=L;
		int i=0;
		while(p->next!=NULL){
				p=p->next;
				i++;
		}
		return i;
}

bool isChild(LinkList A,LinkList B){
		LNode *pa=A->next,*pb=B->next,*p;
		int la=length(A),lb=length(B);
		int i=0;
		while(pa!=NULL&&la-i>=lb){
				if(pa->data==pb->data){
						p=pa->next;
						pb=pb->next;
						while(pb!=NULL){
								if(p->data==pb->data){
										p=p->next;
										pb=pb->next;
								}else{
										break;
								}

						}
						if(pb==NULL) return true;
						pb=B->next;
				}
				pa=pa->next;
				i++;
		}
		return false;
}

bool Pattern(LinkList A,LinkList B){
		LNode *pa=A->next,*pb=B->next,*p=pa;
		while(pa!=NULL&&pb!=NULL){
				if(pa->data==pb->data){
						pa=pa->next;
						pb=pb->next;
				}else{
						p=p->next;
						pa=p;
						pb=B->next;
				}
		}
		if(pb==NULL) return true;
		return false;

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
		LinkList A,B;
		int a[]={1,2,3,2,3,4,5};
		int b[]={2,3,4};
		createList(&A,a,7);
		createList(&B,b,3);
		if(Pattern(A,B)){
				printf("B is A's child.\n");
		}else{
				printf("B is not A's child.\n");
		}
		return 0;
}

