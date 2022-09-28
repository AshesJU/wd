#include<stdio.h>
#define MAXLEN 255

typedef struct{
		char ch[MAXLEN];
		int length;
}SString;

int Index(SString S,SString T){
		int i=1,j=1,k=1;
		while(i<=S.length&&j<=T.length){
				if(S.ch[i]==T.ch[j]){
						i++;
						j++;
				}else{
						i=++k;
						j=1;
				}
		}
		if(j>T.length){
				return k;
		}else{
				return 0;
		}
}
