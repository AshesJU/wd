#include<stdio.h>
#include<stdbool.h>
int abs_(int a){
		if(a>=0) return a;
		else return -a;
}

bool isMin(int a,int b,int c){
		if(a>b||a>c) return false;
		else return true;
}

int MinDist(int S1[],int S2[],int S3[],int n1,int n2,int n3){
		int D_min=1000000;
		int D;
		int i=0,j=0,k=0;
		while(i<n1&&j<n2&&k<n3){
				D=abs_(S1[i]-S2[j])+abs_(S2[j]-S3[k])+abs_(S3[k]-S1[i]);
				if(D<D_min)
						D_min=D;
				if(isMin(S1[i],S2[j],S3[k])){
						i++;
				}else if(isMin(S2[j],S1[i],S3[k])){
						j++;
				}else k++;			
		}
		return D_min;
}

int main(){
		int S1[]={-1,0,9};
		int S2[]={-25,-10,10,11};
		int S3[]={2,9,17,30,41};
		int minD=MinDist(S1,S2,S3,3,4,5);
		printf("%d\n",minD);
		return 0;
}
