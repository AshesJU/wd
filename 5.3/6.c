#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
		int data;
		struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTNode *PreInCreate(int A[],int B[],int l1,int h1,int l2,int h2){
		BiTree root=(BiTNode*)malloc(sizeof(BiTNode));
		root->data=A[l1];
		int i,llen,rlen;
		for(i=l2;B[i]!=A[l1];i++);
		llen=i-l2;
		rlen=h2-i;
		if(llen!=0){
				root->lchild=PreInCreate(A,B,l1+1,l1+llen,l2,l2+llen-1);
		}else{
				root->lchild=NULL;
		}
		if(rlen!=0){
				root->rchild=PreInCreate(A,B,h1-rlen+1,h1,h2-rlen+1,h2);
		}else{
				root->rchild=NULL;
		}
		return root;
		
}

void PreOrder(BiTree T){
		if(T!=NULL){
				printf("%d ",T->data);
				PreOrder(T->lchild);
				PreOrder(T->rchild);
		}
}

int main(){
		int A[]={-1,1,2,4,5,3,6,7};
		int B[]={-1,4,2,5,1,6,3,7};
		BiTree T=PreInCreate(A,B,1,7,1,7);
		PreOrder(T);
		printf("\n");
		return 0;
}
