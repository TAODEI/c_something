#include<stdio.h>
void main(){
	int i,a;
	printf("整数：");
	scanf("%d",&a);
	for(i=1;i<=a;i+=1)
		printf("%d",i%10);
	printf("\n");
}
