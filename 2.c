#include<stdio.h>
void main(){
	int a,b,i;
	scanf("%d",&a);
	if(a>99&&a<1000){
		b=(a%10)*(a%10)*(a%10)+(a/10%10)*(a/10%10)*(a/10%10)+(a/100)*(a/100)*(a/100);
		if(a==b) putchar('Y');
		else putchar('N');
	}
	else putchar('N');
	putchar('\n');
}
