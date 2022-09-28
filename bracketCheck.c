#include<stdio.h>
#include<stdbool.h>

#define MaxSize 10

typedef struct{
		char data[MaxSize];
		int top;
}SqStack;

void InitStack(SqStack *S){
		S->top=-1;
}

bool StackEmpty(SqStack S){
		return S.top==-1;
}

bool Push(SqStack *S,char x){
		if(S->top+1==MaxSize) return false;
		S->data[++S->top]=x;
		printf("Push %c\n",x);
		return true;
}

bool Pop(SqStack *S,char *x){
		if(S->top==-1) return false;
		*x=S->data[S->top--];
		printf("Pop %c\n",*x);
		return true;
}

bool bracketCheck(char str[]){
		SqStack S;
		InitStack(&S);
		char c;
		int i;
		while(str[i]!='\0'){
				if(str[i]=='('||str[i]=='{'||str[i]=='['){
						Push(&S,str[i]);
				}else{
						if(StackEmpty(S)) return false;
						Pop(&S,&c);
						if(str[i]==')'&&c!='(') return false;
						if(str[i]=='}'&&c!='{') return false;
						if(str[i]==']'&&c!='[') return false;
				}
				i++;
		}
		return StackEmpty(S);
}

int main(){
		char str[]="([{[]}])";
		if(bracketCheck(str)) printf("Match success.\n");
		else printf("Match fail.\n");
		return 0;
}
