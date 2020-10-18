 #include<stdio.h>
 int i,b,c[100],num=0;
 void r(int v[],int n,int key){
         for(i=0;i<n;i++){
                 if(v[i]==key){
                         c[num]=i+1;
                         num++;}
         }}
 void main(){
         printf("数组长度为：\n");
         scanf("%d",&b);
         int a[b],ky;
         for(i=0;i<b;i++){
                 printf("[%d]:",i);
                 scanf("%d",&a[i]);
         }
         printf("请输入要查找的值：");
         scanf("%d",&ky);
         r(a,b,ky);
         for(i=0;i<num;i++){
                 printf("%d ",c[i]);}
         printf("个数为：%d\n",num);}

