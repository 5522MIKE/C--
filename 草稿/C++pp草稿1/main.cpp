#include<iostream>
#include<stdio.h>
using namespace std;

int a[1000000010]={0};

 int main()
 {
     int T,i,j,k,n,m,max,min,count=o;

     scanf("%d",&T);

     //��ȡ��������
     for(i=0;i<T;i++)
     {
         //������
         scanf("%d",&n);

         //����߶ȣ������
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
