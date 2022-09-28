#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

typedef struct BiTNode{
		int INFO;
		struct BiTNode *LLINK,*RLINK;
}BiTNode,*BiTree;
//设p在q的左边
BiTree ANCESTOR(BiTree ROOT,BiTree p,BiTree q){
		BiTree S[MaxSize],P[MaxSize];
		int top=-1,top1;
		BiTree n=ROOT,s=NULL;
		while(n||top>-1){
				if(n){
						S[++top]=n;
						n=n->LLINK;
				}else{
						n=S[top];
						if(n->RLINK&&n->RLINK!=s){
								n=n->RLINK;
						}else{
								n=S[top--];
								if(n==p){
										int i=top;
										while(i>=0){
												P[i]=S[i];
												i--;
										}
										top1=top;
								}
								if(n==q){
										for(int i=top;i>=0;i--){
												for(int j=top1;j>=0;j--){
														if(S[i]==P[j]){
																return S[i];
														}
												}
										}
								}
								s=n;
								n=NULL;
						}
				}
		}
}

int main(){
		BiTree T=(BiTNode*)malloc(sizeof(BiTNode));
		BiTNode *n2=(BiTNode*)malloc(sizeof(BiTNode));
		BiTNode *n3=(BiTNode*)malloc(sizeof(BiTNode));
		BiTNode *n4=(BiTNode*)malloc(sizeof(BiTNode));
		BiTNode *n5=(BiTNode*)malloc(sizeof(BiTNode));
		BiTNode *n6=(BiTNode*)malloc(sizeof(BiTNode));
		BiTNode *n7=(BiTNode*)malloc(sizeof(BiTNode));
		BiTNode *n8=(BiTNode*)malloc(sizeof(BiTNode));
		T->INFO=1;
		n2->INFO=2;
		n3->INFO=3;
		n4->INFO=4;
		n5->INFO=5;
		n6->INFO=6;
		n7->INFO=7;
		n8->INFO=8;
		T->LLINK=n2;
		T->RLINK=n3;
		n2->LLINK=n4;
		n2->RLINK=n5;
		n3->LLINK=n6;
		n3->RLINK=n7;
		n4->LLINK=n8;
		n4->RLINK=NULL;
		n5->LLINK=NULL;
		n5->RLINK=NULL;
		n6->LLINK=NULL;
		n6->RLINK=NULL;
		n7->LLINK=NULL;
		n7->RLINK=NULL;
		n8->LLINK=NULL;
		n8->RLINK=NULL;
		BiTNode *r=NULL;
		r=ANCESTOR(T,n8,n4);
		printf("%d\n",r->INFO);
		return 0;
}
