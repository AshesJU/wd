#include<stdio.h>
#include<stdbool.h>
#define MaxSize 50

typedef struct TreeNode{
		int value;
		bool isEmpty;
}TreeNode;

int main(){
		TreeNode T[MaxSize];
		for(int i=0;i<MaxSize;i++){
				T[i++].isEmpty=true;
		}
		return 0;
}
