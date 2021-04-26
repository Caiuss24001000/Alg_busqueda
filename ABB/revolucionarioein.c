#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,n,A[20],temp,c=1,j;
	scanf("%d",&n);
	for (i=1;i<n;i++){
		for(j=n;j>1;j/=2){/*
			temp=A[j];
			A[j]=A[j+1];
			A[j+1]=temp;*/
			printf("%d               ",j);
			c=c+1;
		}
	}
	return 0;
}
