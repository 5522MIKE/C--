#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1,s2,s3;
    cout<<"Please entry two character strings: ";
    cin>>s1;
    cin>>s2;
    cout<<"show: "<<s1<<" "<<s2<<endl;
    cout<<endl;

    s2 += s1;
    cout<<"s2=s2+s1:"<<s2<<endl;
    cout<<"length of s2:"<<s2.length()<<endl;
    cout<<endl;

    s2 = s1;
    cout<<"s2=s1:"<<s2<<endl;
    cout<<endl;

    cout<<"s2<s1:"<<(s2<s1)<<endl;
    cout<<endl;

    cout<<"s2=s1:"<<(s2==s1)<<endl;
    cout<<endl;

    s3 = s1 + s2;
    cout<<"s3=s1+s2="<<s3<<endl;
    cout<<endl;

//ртобн╙
    return 0;
}
