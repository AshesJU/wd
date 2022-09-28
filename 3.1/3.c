#include<stdio.h>
#include<stdbool.h>

bool legitimate_serial(char a[]){
	int i=0;
	int n_push=0,n_pop=0;
	while(a[i]!='\0'){
			if(a[i]=='I') n_push++;
			if(a[i]=='O') n_pop++;
			if(n_pop>n_push){
					printf("Serial illegitimate\n");
					return false;
			}
			i++;
	}
	if(n_pop!=n_push){
			printf("Serial illegitimate\n");
			return false;
	}else{
			printf("Serial legitimate\n");
			return true;
	}
}

int main(){
		char A[]="IOIIOIOO";
		char B[]="IOOIOIIO";
		char C[]="IIIOIOIO";
		char D[]="IIIOOIOO";
		legitimate_serial(A);
		legitimate_serial(B);
		legitimate_serial(C);
		legitimate_serial(D);
		return 0;
}
