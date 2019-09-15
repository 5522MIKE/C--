#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class point
{
public:
    point():x(0),y(0){}
    void setxy(float m,float n)
    {
        x=m;
        y=n;
    }
    float getx(){return x;}
    float gety(){return y;}
    friend float line(point &a,point &b);
private:
    float x,y;
};
float line(point &a,point &b)
{
    float s;
    s=sqrt((a.getx()-b.getx())*(a.getx()-b.getx())+(a.gety()-b.gety())*(a.gety()-b.gety()));
    return s;
}
int main()
{
    vector<point>a(5);
    float b[5][5];
    float x,y,s=0,l,g=0,p;
    int i,j,k,v=0;
    for(i=0;i<5;i++)
    {
        cin>>x>>y;
        a[i].setxy(x,y);
    }
    for(i=0;i<5;i++)
    {
        k=0;
        for(j=0;j<5;j++)
            {
                if(i==j)
                    j++;
                l=line(a[i],a[j]);
                b[i][k]=l;
                k++;
            }
    }
     for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
            {
                s=s+b[i][j];
            }
    }
 for(i=0;i<4;i++)
    {
        p=b[v][0];
        cout<<p<<" ";
        for(j=0;j<4;j++)
            {
                if(p>b[v][j+1])
                {
                    v=j+1+1;
                    p=b[v][j+1];
                }
            }
            if(v==0)
            {
                v=v+1;
            }
            cout<<p<<"  ";
            g=g+p;
    }
    for(i=0;i<5;i++)
    {
        cout<<"("<<a[i].getx()<<","<<a[i].gety()<<")"<<endl;
    }
    cout<<s/2<<endl;
    cout<<g<<endl;
    return 0;
}
