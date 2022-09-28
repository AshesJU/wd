#include<stdio.h>
#define MaxSize 50

double p(double x,int n){
		struct stack{
				int no;
				double val;
		}st[MaxSize];
		int top=-1,i;
		double fv1=1,fv2=2*x;
		for(i=n;i>=2;i--){
				st[++top].no=i;
		}
		while(top>0){
				st[top].val=2*x*fv2-2*(st[top].no-1)*fv1;
				fv1=fv2;
				fv2=st[top].val;
				top--;
		}
		if(n==0){
				return fv1;
		}
		return fv2;
}

int main(){
		printf("%.2f\n",p(3,4));
		return 0;
}
