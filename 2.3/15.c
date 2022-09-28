#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

void merge(LinkList *A,LinkList *B){
		LNode *pa=(*A)->next,*pb=(*B)->next,*r=*A;
		LNode *temp;
		while(pa!=NULL&&pb!=NULL){
				if(pa->data==pb->data){
						r->next=pa;
						r=r->next;
						pa=pa->next;
						temp=pb;
						pb=pb->next;
						free(temp);
				}else if(pa->data<pb->data){
						temp=pa;
						pa=pa->next;
						free(temp);
				}else{
						temp=pb;
						pb=pb->next;
						free(temp);
				}
		}
		if(pb) pa=pb;
		while(pa){
				temp=pa;
				pa=pa->next;
				free(pa);
		}
		r->next=NULL;
		free(*B);
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
		int a[]={1,3,4,7,9,10,11,13,14,15};
		int b[]={1,2,3,6,7,8,11,12};
		createList(&A,a,10);
		createList(&B,b,8);
		show(A);show(B);
		merge(&A,&B);
		show(A);
		return 0;
}
