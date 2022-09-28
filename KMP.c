#include<stdio.h>
#define MAXLEN 255

typedef struct{
		char ch[MAXLEN];
		int length;
}SString;

void get_next(SString T,int next[]){
		next[1]=0;
		int i=1,j=0;
		while(i<=T.length){
				if(j==0||T.ch[i]==T.ch[j]){
						i++;
						j++;
						next[i]=j;
				}else{
						j=next[j];
				}
		}
}

int KMP(SString S,SString T,int next[]){
		int i=1,j=1;
		while(i<=S.length&&j<=T.length){
				if(S.ch[i]==T.ch[j]||j==0){
						i++;
						j++;
				}else{
						j=next[j];
				}
		}
		if(j>T.length){
				return i-T.length;
		}else{
				return 0;
		}
}

void get_nextval(SString T,int nextval[]){
		nextval[1]=0;
		int i=1,j=0;
		while(i<T.length){
				if(T.ch[i]==T.ch[j]||j==0){
						i++;
						j++;
						if(T.ch[i]!=T.ch[j]) nextval[i]=j;
						else nextval[i]=nextval[j];
				}else{
						j=nextval[j];
				}
		}
}

void StrAssign(SString *S,char str[]){
		int i=0,j=1;
		S->length=0;
		while(str[i]!='\0'){
				S->ch[j++]=str[i++];
				S->length++;
		}
}

void Show(SString S){
		int i=1;
		while(i<=S.length){
				printf("%c ",S.ch[i++]);
		}
		printf("\n");
}

int main(){
		SString S,T;
		StrAssign(&S,"aaacaaaab");
		StrAssign(&T,"aaaab");
		Show(S);
		Show(T);
		int nextval[20];
		get_nextval(T,nextval);
		int i=1;
		while(i<=5){
				printf("%d ",nextval[i++]);
		}
		printf("\n");
		printf("%d\n",KMP(S,T,nextval));
		return 0;

}

