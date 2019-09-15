#include<iostream>
#include<stdio.h>
using namespace std;

int a[1000000010]={0};

 int main()
 {
     int T,i,j,k,n,m,max,min,count=o;

     scanf("%d",&T);

     //获取地面数据
     for(i=0;i<T;i++)
     {
         //地面宽度
         scanf("%d",&n);

         //地面高度，找最高
         max=0;
         for(j=0;j<n;j++)
         {
             scanf("%d",&a[j]);
             if(max<a[j])
            {
                max=a[j];
                k=j;
            }
         }
         for(j=0;j<n;j++)
         {
             if(a[j]>0)
             {

             }
         }
     }
 }
