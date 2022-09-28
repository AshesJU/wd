#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Linknode{
		int data;
		struct Linknode *next;
}Linknode,*LiStack;

void InitStack(LiStack *S){
		*S=(Linknode*)malloc(sizeof(Linknode));
		(*S)->next=NULL;
}

bool Push(LiStack *S,int x){
		Linknode *s=(Linknode*)malloc(sizeof(Linknode));
		if(!s) return false;
		s->data=x;
		s->next=(*S)->next;
		(*S)->next=s;
		return true;
}

bool Pop(LiStack *S,int *x){
		if((*S)->next==NULL) return false;
		*x=(*S)->next->data;
		Linknode *p=(*S)->next;
		(*S)->next=p->next;
		free(p);
		return true;
}

bool GetTop(LiStack S,int *x){
		if(S->next==NULL) return false;
		*x=S->next->data;
		return true;
}

bool StackEmpty(LiStack S){
		if(S->next==NULL) return true;
		else return false;
}

int main(){
		LiStack S;
		int e;
		InitStack(&S);
		if(StackEmpty(S)) printf("Empty stack\n");
		if(Push(&S,1)) printf("Push:%d\n",1);
		if(Push(&S,2)) printf("Push:%d\n",2);
		if(GetTop(S,&e)) printf("Top element:%d\n",e);
		if(Pop(&S,&e)) printf("Pop:%d\n",e);
		if(GetTop(S,&e)) printf("Top element:%d\n",e);
		if(Pop(&S,&e)) printf("Pop:%d\n",e);
		return 0;
}

