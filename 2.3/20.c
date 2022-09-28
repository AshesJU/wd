#include<stdio.h>
#include<stdlib.h>

typedef struct DNode{
		int data;
		struct DNode *pred,*next;
		int freq;
}DNode,*DLinkList;


DNode* Locate1(DLinkList *L,int x){
		DNode *p=(*L)->next,*q;
		while(p!=NULL&&p->data!=x){
				p=p->next;
		}
		if(p->data==x){
				p->freq++;
				q=(*L)->next;
				while(q!=p){
						if(p->freq>=q->freq){
								p->pred->next=p->next;
								if(p->next!=NULL) p->next->pred=p->pred;
								p->next=q;
								p->pred=q->pred;
								if(q->next==p) q->next=p->next;
								q->pred->next=p;
								q->pred=p;
								break;
						}
						q=q->next;
				}
				return p;
		}
		return NULL;
}

DNode* Locate2(DLinkList *L,int x){
		DNode *p=(*L)->next,*q=(*L)->next;
		while(p&&p->data!=x){
				p=p->next;
		}
		if(!p) return NULL;
		p->freq++;
		while(q&&q->freq>p->freq){
				q=q->next;
		}
		if(p==q){
				return p;
		}
		if(p->next!=NULL)
				p->next->pred=p->pred;
		p->pred->next=p->next;
		p->pred=q->pred;
		p->next=q;
		p->pred->next=p;
		q->pred=p;
		return p;
}

DNode* Locate(DLinkList *L,int x){
		DNode *p=(*L)->next,*q;
		while(p&&p->data!=x){
				p=p->next;
		}
		if(!p) return NULL;
		p->freq++;
		if(p->pred==*L||p->pred->freq>p->freq)
				return p;
		if(p->next!=NULL) 
				p->next->pred=p->pred;
		p->pred->next=p->next;
		q=p->pred;
		while(q!=*L&&q->freq<=p->freq){
				q=q->pred;
		}
		p->next=q->next;
		if(q->next!=NULL) q->next->pred=p;
		p->pred=q;
		q->next=p;
		return p;
}

void createDList(DLinkList *L,int a[],int n){
		int i;
		*L=(DNode*)malloc(sizeof(DNode));
		(*L)->next=NULL;
		(*L)->pred=NULL;
		(*L)->freq=0;
		DNode *s,*pre=*L;
		for(i=0;i<n;i++){
				s=(DNode*)malloc(sizeof(DNode));
				s->data=a[i];
				s->freq=0;
				s->pred=pre;
				pre->next=s;
				pre=pre->next;
		}
		pre->next=NULL;
}

void show(DLinkList L){
		DNode *p=L;
		while(p->next!=NULL){
				printf("%d(%d) ",p->next->data,p->next->freq);
				p=p->next;
		}
		printf("\n");
}

int main(){
		DLinkList L;
		int a[]={1,2,3,4,5,6,7,8};
		createDList(&L,a,8);
		show(L);
		Locate(&L,5);
		printf("Locate(5):");
		show(L);
		Locate(&L,3);
		printf("Locate(3):");
		show(L);
		Locate(&L,5);
		printf("Locate(5):");
		show(L);
		Locate(&L,7);
		printf("Locate(7):");
		show(L);
		Locate(&L,7);
		printf("Locate(7):");
		show(L);
		Locate(&L,8);
		printf("Locate(8):");
		show(L);
	
		return 0;
}
