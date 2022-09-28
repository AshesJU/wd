#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

void split_val(LinkList *A,LinkList *B){
		*B=(LNode*)malloc(sizeof(LNode));
		LNode *p=(*A)->next,*pre=*A,*r=*B;
		while(p!=NULL){
				if(p->data%2==0){
						pre->next=p->next;
						r->next=p;
						r=r->next;
				}else{
						pre=pre->next;
				}
				p=p->next;
		}
		r->next=NULL;
}

LinkList split_serial(LinkList *A){
		int i=1;
		LinkList B=(LNode*)malloc(sizeof(LNode));
		LNode *pa=*A,*pb=B,*p=(*A)->next;
		while(p!=NULL){
				if(i%2==0){
						pa->next=p->next;
						pb->next=p;
						pb=pb->next;
				}else{
						pa=pa->next;
				}
				p=p->next;
				i++;
		}
		pb->next=NULL;
		pa->next=NULL;
		return B;
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
		LinkList L1;
		int a[]={1,2,3,4,5,6,7,8,9,10};
		createList(&L,a,10);
		show(L);
		printf("\n");
		L1=split_serial(&L);
		show(L);
		printf("\n");
		show(L1);
		return 0;

}



