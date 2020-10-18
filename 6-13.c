#include<stdio.h>
void s(const int a[3][2],const int b[3][2],int c [2][3][2]){
	int i,j;
	putchar('{');
	for (i=0;i<3;i++){
		for (j=0;j<2;j++)
			c[1][i][j]=a[i][j];
	}
	for (i=0;i<3;i++){
		for (j=0;j<2;j++)
		        c[2][i][j]=b[i][j];
		            }
	for (i=0;i<3;i++){
		for (j=0;j<2;j++)
	printf("%4d",c[1][i][j]);}
	for (i=0;i<3;i++){
		for (j=0;j<2;j++)
	printf("%4d",c[2][i][j]);
	}
	putchar('}');
	putchar('\n');
}
void main(){
	int t1[3][2]={{3,4},{5,6},{99,8}};
	int t2[3][2]={{99,4},{77,46},{888,1}};
	int t[2][3][2];
	s(t1,t2,t);
}
