#include<stdio.h>
#define MaxSize 5

typedef struct{
		int data[MaxSize];
		int top[2];
}stk;

void InitStack(stk *s){
		s->top[0]=-1;
		s->top[1]=MaxSize;
}

int push(stk *s,int i,int x){
	if(i!=1&&i!=2){
				printf("Wrong stack number\n");
				return 0;
		}
		if(s->top[1]-s->top[0]==1){
				printf("Stack Overflow\n");
				return 0;
		}
		switch(i){
				case 1:s->data[++s->top[0]]=x; printf("push %d into stack %d\n",x,i); return 1;
				case 2:s->data[--s->top[1]]=x; printf("push %d into stack %d\n",x,i); return 1;
		}
}

int pop(stk *s,int i){
		if(i!=1&&i!=2){
				printf("Wrong stack number\n");
				return -1;
		}
		if((i==1&&s->top[0]==-1)||(i==2&&s->top[1]==MaxSize)){
				printf("stack empty.\n");
				return -1;
		}
		if(i==1){
				return s->data[s->top[0]--];
				
		}else{
				return s->data[s->top[1]++];
		}
}

int main(){
		stk s;
		InitStack(&s);
		push(&s,1,1);
		push(&s,2,5);
		push(&s,2,4);
		push(&s,1,2);
		push(&s,1,3);
		push(&s,1,3);
		printf("pop %d\n",pop(&s,1));
		printf("pop %d\n",pop(&s,1));
		printf("pop %d\n",pop(&s,1));
		printf("pop %d\n",pop(&s,1));
		printf("pop %d\n",pop(&s,2));
		printf("pop %d\n",pop(&s,2));
		printf("pop %d\n",pop(&s,2));

		return 0;
}
