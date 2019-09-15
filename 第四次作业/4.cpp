#include<iostream>
using namespace std;
int main()
{
    int i,sum,s;
    bool flag = false;
    for(i=1;i<400;i++)
    {
        sum = 0;
        for(int j=1;j<i;j++)
        {
            if(i%j == 0)
            {
                sum += j;
            }
        }
        for(int j=1;j<i;j++)
        {
            if(sum%j == 0)
            {
                s += j;
            }
        }
        if(s == i)
        {
            cout<<s<<" "<<i<<endl;
            break;
        }
    }
}
