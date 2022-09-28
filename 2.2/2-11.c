#include<stdio.h>
#include<stdbool.h>

/*分别对A、B求中位数，设为a、b，在求a、b过程中：
1.a=b，a或b即为所求中位数，算法结束；
2.a<b，舍弃A序列较小的一部分，舍去B序列中较大的一部分。
3.a>b，舍去A序列较大的一部分，舍去B序列中较小的一部分。
重复1，2，3直到两个序列只剩一个元素为止
*/
int Mid_A_B(int A[],int B[],int n){
		int s1=0,d1=n-1,m1,s2=0,d2=n-1,m2;
		while(s1<d1||s2<d2){
				m1=(s1+d1)/2;
				m2=(s2+d2)/2;
				if(A[m1]==B[m2]){
						return A[m1];
				}else if(A[m1]<B[m2]){
						if((s1+d1)%2==0){ //A序列个数为奇数
								s1=m1;
								d2=m2;
						}else{//序列个数为偶数
								s1=m1+1;
								d2=m2;
						}
				}else{
						if((s1+d1)%2==0){
								d1=m1;
								s2=m2;
						}else{
								d1=m1;
								s2=m2+1;
						}
				}
		}
		return A[s1]<B[s2]?A[s1]:B[s2];
}

int main(){
		int A[]={11,13,15,17,19};
		int B[]={2,4,6,8,20};
		int m=Mid_A_B(A,B,5);
		printf("%d\n",m);

		return 0;
}
