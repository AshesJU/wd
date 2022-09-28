#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

void merge(LinkList *A,LinkList *B){
		LNode *pa,*pb,*r;
		pa=(*A)->next;
		pb=(*B)->next;
		(*A)->next=NULL;
		free(*B);
		while(pa!=NULL&&pb!=NULL){
				if(pa->data<pb->data){
						r=pa->next;
						pa->next=(*A)->next;
						(*A)->next=pa;
						pa=r;
				}else{
						r=pb->next;
						pb->next=(*A)->next;
						(*A)->next=pb;
						pb=r;
				}
		}
		if(pa) pb=pa;
		while(pb!=NULL){
			r=pb->next;
			pb->next=(*A)->next;
			(*A)->next=pb;
			pb=r;
		}
}

void show(LinkList L){
		if(L==NULL) return;
		LNode *p=L->next;
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
		int a[]={1,3,4,7,8,11,20};
		int b[]={2,3,5,6,9,10};
		createList(&A,a,7);
		createList(&B,b,6);
		show(A);
		show(B);
		merge(&A,&B);
		show(A);
		return 0;

}

