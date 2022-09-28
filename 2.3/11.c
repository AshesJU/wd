#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

void split(LinkList *C,LinkList *A,LinkList *B){
		int i=1;		
		LNode *p,*r,*ra;
		if(*C==NULL) return;
		if((*C)->next==NULL) return;
		*A=(LNode*)malloc(sizeof(LNode));
		*B=(LNode*)malloc(sizeof(LNode));
		ra=*A;
		p=(*C)->next;
		r=p->next;
		while(p!=NULL){
				if(i%2==0){
						p->next=(*B)->next;
						(*B)->next=p;
				}else{
						ra->next=p;
						ra=p;
				}
				p=r;
				if(r!=NULL)
						r=r->next;
				i++;
		}
		ra->next=NULL;
		free(*C);
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
		LinkList A,B,C;
		int a[]={1,2,3,4,5,6,7,8,9,10};
		createList(&C,a,10);
		show(C);
		printf("\n");
		split(&C,&A,&B);
		show(A);
		printf("\n");
		show(B);
		return 0;
}


