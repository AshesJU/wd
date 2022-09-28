#include<stdio.h>

int MainElem(int A[],int n){
		int num=A[0];
		int c=1;
		int i;
		for(i=1;i<n;i++){
			if(A[i]==num){
					c++;
			}else{
					c--;
					if(c==0){
							num=A[i];
							c=1;
					}
			}
		}
		for(i=0,c=0;i<n;i++){
				if(A[i]==num)
						c++;
		}
		if(c>n/2){
				return num;
		}else{
				return -1;
		}
}

int main(){
		int A[]={0,5,5,3,5,7,5,5};
		int num=MainElem(A,8);
		printf("%d\n",num);
		return 0;
}
