#include<iostream>
#include<math.h>
using namespace std;
class circle
{
public:
    circle():r(r),s(s){}
    void setr(float a)
    {
        r=a;
    }
    float getr()
    {
        return r;
    }
    float gets()
    {
        s=3.14*r*r;
        return s;
    }
private:
    float r,s;
};
class zhui:public circle
{
public:
    zhui():S(0),V(0),h(0){}
    void setdata(float a,float b)
    {
        setr(a);
        h=b;
    }
    float getS()
    {
        float a=gets();
        float b=getr();
        S=a+3.14*b*sqrt(h*h+b*b);
        return S;
    }
    float getV()
    {
        float a=gets();
        V=a*h/3;
        return V;
    }
private:
    float V,S,h;
};
class globe:public circle
{
public:
    globe():S(0),V(0){}
    void setdata(float a)
    {
        setr(a);
    }
    float getS()
    {
        float a=getr();
        S=4*3.14*a*a;
        return S;
    }
    float getV()
    {
        float a=getr();
        V=(4/3)*3.14*a*a*a;
        return V;
    }
private:
    float S,V;
};
class zhu:public circle
{
public:
    zhu():S(0),V(0),h(0){}
    void setdata(float a,float b)
    {
        setr(a);
        h=b;
    }
    float getS()
    {
        float a=getr();
        float b=gets();
        S=b+h*2*3.14*a;
        return S;
    }
    float getV()
    {
        float a=gets();
        V=a*h;
        return V;
    }
private:
    float S,V,h;
};
int main()
{
    zhui a;
    globe b;
    zhu c;
    cout<<"��������Բ׶�ĵײ��뾶�͸ߣ���İ뾶��Բ���ĵײ��뾶�͸�"<<endl;
    float m,n,o,x,y;
    cin>>m>>n;
    cin>>o;
    cin>>x>>y;
    a.setdata(m,n);
    b.setdata(o);
    c.setdata(x,y);
    cout<<"Բ׶����Բ���ı�������������Ϊ��"<<endl;
    cout<<a.getS()<<"  "<<a.getV()<<endl;
    cout<<b.getS()<<"  "<<b.getV()<<endl;
    cout<<c.getS()<<"  "<<c.getV()<<endl;
    return 0;
}
