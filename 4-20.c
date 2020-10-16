#include<stdio.h>
void main()
{	printf("   |");
	int i,j,a;
	for (a=1;a<=9;a++)
		printf("%3d",a);
	printf("\n-------------------------------\n");
	for (i=1;i<=9;i++){
		printf("%3d|",i);
		for(j=1;j<=9;j++)
			printf("%3d",i*j);
		putchar('\n');}


}
