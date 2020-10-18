#include<stdio.h>
void main()
{
	int i,j;
	int shu[6],yu[6],sum[6];
	printf("请输入六名学生的数学成绩：\n");
	for(i=0;i<6;i++){
		printf("%2d号：",i+1);
		do{
			scanf("%d",&shu[i]);
			if (shu[i]<0||shu[i]>100)
				printf("\a请输入0～100的数：");
		}while(shu[i]<0||shu[i]>100);}
	printf("请输入六名学生的语文成绩：\n");
        for(i=0;i<6;i++){
                printf("%2d号：",i+1);
                do{
                        scanf("%d",&yu[i]);
                        if (yu[i]<0||yu[i]>100)
                                printf("\a请输入0～100的数：");
                }while(yu[i]<0||yu[i]>100);}
	int sum1=0,sum2=0;
	for(i=0;i<6;i++){
		sum2+=yu[i];
		sum1+=shu[i];
	}
	printf("数学的总分为：%d  平均分为：%d\n",sum1,sum1/6);
	printf("语文的总分为：%d  平均分为：%d\n",sum2,sum2/6);
	for(i=0;i<6;i++)
		printf("学生%d的总分为%d\n",i+1,shu[i]+yu[i]);
}

















