#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

/*算法思想:创建指针p，q指向表头结点，若p的后继结点为p到q结点中的任何一个，则说明链表有环，否则，p指向p的后继结点，直到p为空。*/

LNode* CircleEntry(LinkList L){
		LNode *p=L->next,*q;
		if(L->next==L) return L;
		while(p!=NULL){
				q=L;
				while(q!=p){
						if(p->next==q||p->next==p) return q;
						q=q->next;
				}
				p=p->next;
		}
		return NULL;
		//时间复杂度o(n^2)。
}

/*算法思想:设置两个指针都指向表头，一个每次指向下一个结点，另一个每次指向后一个结点，若存在循环，两指针会相遇（指针指向地址相同），若不存在循环，则快指针将指向空地址。*/

LNode* FindLoopStart(LinkList L){
		LNode *fast=L,*slow=L;
		while(fast->next!=NULL||fast->next->next!=NULL){
				fast=fast->next->next;
				slow=slow->next;
				if(fast==slow) break;
		}
		if(fast->next==NULL||fast->next->next==NULL) return NULL;
		LNode *p=L,*q=slow;
		while(p!=q){
				p=p->next;
				q=q->next;
		}
		return p;
		//时间复杂度o(n)
}

int main(){
		LinkList L;
		LNode *a,*b,*c,*d,*start;
		L=(LNode*)malloc(sizeof(LNode));
		a=(LNode*)malloc(sizeof(LNode));
		b=(LNode*)malloc(sizeof(LNode));
		c=(LNode*)malloc(sizeof(LNode));
		d=(LNode*)malloc(sizeof(LNode));
		L->next=a;L->data=666;
		a->next=b;a->data=1;
		b->next=c;b->data=2;
		c->next=d;c->data=3;
		d->next=L;d->data=4;
		start=FindLoopStart(L);
		if(start) printf("%d\n",start->data);
		else printf("No loop.\n");
		return 0;
}
