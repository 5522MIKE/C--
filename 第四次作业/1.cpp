/*
#include<iostream>
using namespace std;
main()
{
    int *p1,a=0,b=2;
    p1=&a;
    int* &p3=p1;
cout<<"指针中的地址是:"<<p1<<"   "<<p3<<endl;
cout<<"指针中的地址取出的内容是:"<<*p1<<"   "<<*p3<<endl;
cout<<"保存该指针的地址是:"<<&p1<<"   "<<&p3<<endl;
    p1=&b;
cout<<"指针中的地址是:"<<p1<<"   "<<p3<<endl;
cout<<"指针中的地址取出的内容是:"<<*p1<<"   "<<*p3<<endl;
cout<<"保存该指针的地址是:"<<&p1<<"   "<<&p3<<endl;
}
*/
#include<iostream>
using namespace std;
void assign(int *&p1,int * &p2, int*p3)
{
        int a=1;
       p1=&a;
       p2=new int[1];
       p2[0]=2;
       p3=new int[1];
       p3[0]=3;
}
main()
{
       int *p1,*p2, *p3=NULL;
       cout<<"p3:"<<p3<<endl;
       assign(p1,p2,p3);
    if(p1!=NULL)cout<<"p1:"<<p1[0]<<endl;                //p1是个野指针
       else cout<<"p1指针为空"<<endl;
       if(p2!=NULL)cout<<"p2:"<<p2[0]<<endl;       //使用了指针的引用，p2非空，
    else cout<<"p2指针为空"<<endl;
       if(p3!=NULL)cout<<"p3:"<<p3[0]<<endl;         //p3还是空指针
     else cout<<"p3指针为空"<<endl;
     cout<<"p3:"<<p3<<endl;
     delete p2;
     delete p3;
}

//指针传递的是地址的值，所以在函数中开辟空间建立的是实参的副本并没有影响到主函数。而引用则是将实参的值传进来了，影响了主函数
