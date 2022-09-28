#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

LNode* GetElem(LinkList L,int i){
		if(i<0) return NULL;
		int j=0;
		LNode *p=L;
		while(j<i&&p!=NULL){
				p=p->next;
				j++;
		}
		return p;
		
}

LNode* LocateElem(LinkList L,int e){
		LNode *p=L->next;
		while(p!=NULL&&p->data!=e){
				p=p->next;
		}
		return p;
}

int Length(LinkList L){
		LNode *p=L;
		int i=0;
		while(p->next!=NULL){
				p=p->next;
				i++;
		}
		return i;
}

bool ListDelete(LinkList *L,int i,int *e){
		if(L==NULL||i<1) return false;
		int j=0;
		LNode *temp;
		LNode *p=*L;
		while(p!=NULL&&j<i-1){
				p=p->next;
				j++;
		}
		if(p==NULL) return false;
		if(p->next==NULL) return false;
		*e=p->next->data;
		temp=p->next;
		p->next=p->next->next;
		free(temp);
		return true;
}

LinkList List_HeadInsert(LinkList *L){
		int i;
		LNode *s;
		*L=(LNode*)malloc(sizeof(LNode));
		(*L)->next=NULL;
		scanf("%d",&i);
		while(i!=9999){
				s=(LNode*)malloc(sizeof(LNode));
				s->data=i;
				s->next=(*L)->next;
				(*L)->next=s;
				scanf("%d",&i);
		}
		return *L;
}

LinkList List_TailInsert(LinkList *L){
		LNode *s,*r=*L;
		int i;
		*L=(LNode*)malloc(sizeof(LNode));
		(*L)->next=NULL;
		scanf("%d",&i);
		while(i!=9999){
				s=(LNode*)malloc(sizeof(LNode));
				s->data=i;
				r->next=s;
				r=r->next;
				scanf("%d",&i);
		}
		r->next=NULL;
		return *L;
		
}

bool InsertPriorNode(LNode *p,LNode *s){
		if(p==NULL||s==NULL) return false;
		int temp=p->data;
		p->data=s->data;
		s->data=temp;
		s->next=p->next;
		p->next=s;
		return true;
}

bool InsertNextNode(LNode *p,int e){
		if(p==NULL) return false;
		LNode *s= (LNode*)malloc(sizeof(LNode));
		if(s==NULL) return false;
		s->data=e;
		s->next=p->next;
		p->next=s;
		return true;
}

bool ListInsert(LinkList *L,int i,int e){
		if(i<1) return false;
		LNode *p;
		int j=0;
		p=*L;
		while(p!=NULL&&j<i-1){
				p=p->next;
				j++;
		}
		if(p==NULL) return false;
		LNode *s=(LNode*)malloc(sizeof(LNode));
		s->data=e;
		s->next=p->next;
		p->next=s;
		return true;
}

bool NoHeadListInsert(LinkList *L,int i,int e){
		if(i<1) return false;
		if(i==1){
				LNode *s =(LNode*)malloc(sizeof(LNode));
				s->data=e;
				s->next=*L;
				*L=s;
				return true;
		}
		int j=1;
		LNode *p;
		p=*L;
		while(p!=NULL&&j<i-1){
				p=p->next;
				j++;
		}
		if(p==NULL) return false;
		LNode *s=(LNode*)malloc(sizeof(LNode));
		s->data=e;
		s->next=p->next;
		p->next=s;
		return true;
				
}

int main(){
		return 0;
}
