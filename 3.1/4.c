#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode{
		char data;
		struct LNode *next;
}LNode,*LinkList;

bool symmetry(LinkList L,int n){
		char c[n/2];
		LNode *p=L->next;
		int i=0;
		while(i<n/2){
				c[i++]=p->data;
				p=p->next;
		}
		if(n%2==1) p=p->next;
		i--;
		while(p!=NULL){
				if(p->data!=c[i]) return false;
				p=p->next;
				i--;
		}
		return true;
}

void createList(LinkList *L,char a[],int n){
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
		LinkList L;
		char a[]="abcdefgfedcba";
		createList(&L,a,13);
		if(symmetry(L,13)) printf("symmetry\n");
		else printf("not symmetry\n");
		return 0;
}

