#include<iostream>
#include<string>
using namespace std;

class Cdate{
public:
    Cdate(int yy,int mm,int dd)
    {
        y = yy;
        m = mm;
        d = dd;
    }
    Cdate()
    {
        y = 0000;
        m = 00;
        d = 00;
    }
    showdate()
    {
        cout<<"出生日期："<<y<<":"<<m<<":"<<"d"<<endl;
    }
private:
    int y,m,d;
};
class Employee{
public:
    Employee(string n,string s,string c,string p,string pos)
    {
        name = n;
        street = s;
        city = c;
        province = p;
        post = pos;
    }
    Employee(Cdate c):c1(c)
    {
        c1.showdate();
    }
private:
    string name,street,city,province,post;
    Cdate c1;
};
int main()
{

}
