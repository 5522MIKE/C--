/*
#include<iostream>
using namespace std;
main()
{
    int *p1,a=0,b=2;
    p1=&a;
    int* &p3=p1;
cout<<"ָ���еĵ�ַ��:"<<p1<<"   "<<p3<<endl;
cout<<"ָ���еĵ�ַȡ����������:"<<*p1<<"   "<<*p3<<endl;
cout<<"�����ָ��ĵ�ַ��:"<<&p1<<"   "<<&p3<<endl;
    p1=&b;
cout<<"ָ���еĵ�ַ��:"<<p1<<"   "<<p3<<endl;
cout<<"ָ���еĵ�ַȡ����������:"<<*p1<<"   "<<*p3<<endl;
cout<<"�����ָ��ĵ�ַ��:"<<&p1<<"   "<<&p3<<endl;
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
    if(p1!=NULL)cout<<"p1:"<<p1[0]<<endl;                //p1�Ǹ�Ұָ��
       else cout<<"p1ָ��Ϊ��"<<endl;
       if(p2!=NULL)cout<<"p2:"<<p2[0]<<endl;       //ʹ����ָ������ã�p2�ǿգ�
    else cout<<"p2ָ��Ϊ��"<<endl;
       if(p3!=NULL)cout<<"p3:"<<p3[0]<<endl;         //p3���ǿ�ָ��
     else cout<<"p3ָ��Ϊ��"<<endl;
     cout<<"p3:"<<p3<<endl;
     delete p2;
     delete p3;
}

//ָ�봫�ݵ��ǵ�ַ��ֵ�������ں����п��ٿռ佨������ʵ�εĸ�����û��Ӱ�쵽�����������������ǽ�ʵ�ε�ֵ�������ˣ�Ӱ����������
