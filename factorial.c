#include<stdio.h>

int factorial(int x){
		if(x==1||x==0) return 1;
		else return x*factorial(x-1);
}

int main(){
		printf("%d\n",factorial(10));
		return 0;
}
