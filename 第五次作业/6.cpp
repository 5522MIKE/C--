#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
void getin(vector<int> &vec)
{ int val = 0;
char ch;
bool flag = 0, minus = 0;
while(ch = cin.get())
    { if(ch == '\n')
    break;
if(ch == ' ')
    {  vec.push_back(val);
       val = 0;
       flag = 1;
       minus = false;
       continue; }
if(ch == '-')
    { minus = true;
       continue; }
flag = 0;
if(minus == true)
    { val = val*10-(ch-'0'); }
else{ val = val*10+ch-'0'; }
}
if(flag == 0) vec.push_back(val);
}
int main()
 {
    vector<int> vec;
    getin(vec);
    int x,p=0;
    x=vec.size();
    int a[x]={0};
    for(int i=0;i<x;i++)
    {
        p=0;
        if(a[i]==0)
            {
        for(int j=0;j<x;j++)
        {
            if(vec[i]==vec[j])
            {
                p++;
                a[j]=-1;
            }
        }
        cout<<vec[i]<<" "<<p<<endl;
        a[i]=-1;
            }
    }
    cout << endl;
    return 0;
}
