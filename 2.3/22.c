#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
		int data;
		struct LNode *next;
}LNode,*LinkList;

/*
 算法设计思想：遍历一次链表记录链表长度l，若l-k>=0,再次遍历链表至l-k+1处，输出data。返回1，
 若l-k<0,返回0;
 */

int find_k(LinkList L,int k){
		LNode *p=L;
		int l=0,i;
		while(p->next!=NULL){
				p=p->next;
				l++;
		}
		if(k<=0||l-k<=0) return 0;
		p=L;
		for(i=0;i<l;i++){
				p=p->next;
		}
		printf("%d\n",p->data);
		return 1;
}

/*
算法设计思想：设置两个指针p、q同时指向list后继结点，先让p沿链表移动k个结点，再同时沿链表移动p、q，当p等于空时，q指向倒数第k个结点。
*/ 

int search_k(LinkList L,int k){
		int count=0;
		LNode *p=L->next,*q=L->next;
		while(p!=NULL){
				if(count<k)
						count++
				else
						q=q->next;
				p=p->next;
		}
		if(count<k){
				return 0;
		}else{
				printf("%d",q->data);
				return 1;
		}
		
}
