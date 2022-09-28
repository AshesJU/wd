#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

LinkList CommonElem(LinkList A,LinkList B){
		LinkList C;
		LNode *pa,*pb,*pc,*s;
		if(A==NULL||B==NULL) return NULL;
		C=(LNode*)malloc(sizeof(LNode));
		C->next=NULL;
		pa=A->next;
		pb=B->next;
		pc=C;
		while(pa!=NULL&&pb!=NULL){
				if(pa->data==pb->data){
						if(pc==C||pc->data!=pa->data){
								s=(LNode*)malloc(sizeof(LNode));
								s->data=pa->data;
								pc->next=s;
								pc=s;
						}
						pa=pa->next;
						pb=pb->next;
				}else if(pa->data<pb->data){
						pa=pa->next;
				}else{
						pb=pb->next;
				}
		}
		pc->next=NULL;
		return C;
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
		LinkList A,B,C;
		int a[]={1,1,2,4,7,9,10,12};
		int b[]={1,1,2,3,4,9,11,12};
		createList(&A,a,8);
		createList(&B,b,8);
		show(A);
		show(B);
		C=CommonElem(A,B);
		show(C);
		return 0;
}

