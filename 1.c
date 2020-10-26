#include<stdio.h>
void main()
{
	int i,j;
	int n=0;
	for(i=2;i<=100;i++){
		for(j=2;j<=i;j++){
			while(j==i) {printf("%3d",i);n++;
				if(n%5==0) putchar('\n');
				j++;}
			if(i%j==0) break;
			if(i%j!=0) continue;}
				}
putchar('\n');}
