#include<stdio.h>

#define MaxSize 10

typedef struct{
		int data;
		int next;
}SLinkList[MaxSize];

struct Node{
		int data;
		int next;
};
	

int main(){
		SLinkList L;
		printf("%d\n",sizeof(L));
		struct Node a[MaxSize];
		printf("%d\n",sizeof(a));

		return 0;
}
