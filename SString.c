#include<stdio.h>
#include<stdbool.h>
#define MAXLEN 255

typedef struct{
		char ch[MAXLEN];
		int length;
}SString;

typedef struct{
		char *ch;
		int length;
}HString;

int SubString(SString *Sub,SString S,int pos,int len){
		if(pos+len-1>S.length) return false;
		for(int i=pos;i<pos+len;i++){
				Sub->ch[i-pos+1]=S.ch[i];
		}
		Sub->length=len;
		return true;
}

int StrCompare(SString S,SString T){
		int i;
		for(i=0;i<S.length&&i<T.length;i++){
				if(S.ch[i]!=T.ch[i])
						return S.ch[i]-T.ch[i];
		}
		return S.length-T.length;
}

int main(){
		SString Sub,S;
		return 0;
}
