#include<iostream>
#include<string>
using namespace std;
int main()
{
     string a,b;
     cin>>a;
     cin>>b;
     cout<<"+��"<<endl;
     cout<<a+b<<endl;
     cout<<"!=��"<<endl;
     if(a!=b)
        cout<<"a��b����"<<endl;
     cout<<"==��"<<endl;
     if(a==b)
     cout<<"a��b���"<<endl;
     cout<<">��"<<endl;
     if(a>b)
        cout<<"a>b"<<endl;
      cout<<"������"<<endl;
      cout<<a[1]<<endl;
    a=a.replace(a.begin(),a.begin()+2,"#");
      cout<<a<<endl;
       if(b.empty())
        cout<<"bΪ��"<<endl;
        else
            cout<<"b��Ϊ��"<<endl;
        string s=a.substr(0,4);
        cout<<s<<endl;
        int x=a.rfind("#",5);
        cout<<x<<endl;
        cout<<a.max_size()<<endl;
     return 0;
}
