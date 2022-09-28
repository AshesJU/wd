#include<stdio.h>
#include<stdbool.h>
#define MaxSize 10


typedef struct{
		char data[MaxSize];
		int top;
}SqStack;

bool match(char str[]){
		SqStack S;
		S.top=-1;
		int i=0;
		while(str[i]!='\0'){
				if(str[i]=='{'||str[i]=='('||str[i]=='['){
						S.data[++S.top]=str[i];
				}else{		
						if(S.top==-1) return false;
						if(str[i]=='}'&&S.data[S.top]!='{') return false;
						if(str[i]==')'&&S.data[S.top]!='(') return false;
						if(str[i]==']'&&S.data[S.top]!='[') return false;
						S.top--;
				}
				i++;
		}
		if(S.top==-1) return true;
		else return false;
}

int main(){
		char a[]="({[[]]})";
		if(match(a)) printf("true\n");
		else printf("false\n");
		return 0;
}
