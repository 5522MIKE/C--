#include<iostream>
#include<string>
using namespace std;
int main()
{
     string a,b;
     cin>>a;
     cin>>b;
     cout<<"+符"<<endl;
     cout<<a+b<<endl;
     cout<<"!=符"<<endl;
     if(a!=b)
        cout<<"a和b不等"<<endl;
     cout<<"==符"<<endl;
     if(a==b)
     cout<<"a和b相等"<<endl;
     cout<<">符"<<endl;
     if(a>b)
        cout<<"a>b"<<endl;
      cout<<"【】符"<<endl;
      cout<<a[1]<<endl;
    a=a.replace(a.begin(),a.begin()+2,"#");
      cout<<a<<endl;
       if(b.empty())
        cout<<"b为空"<<endl;
        else
            cout<<"b不为空"<<endl;
        string s=a.substr(0,4);
        cout<<s<<endl;
        int x=a.rfind("#",5);
        cout<<x<<endl;
        cout<<a.max_size()<<endl;
     return 0;
}
