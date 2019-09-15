#include<iostream>
#include"Point.h"
using namespace std;

Point::resetPoint(int xx,int yy)
{
    x = xx;
    y = yy;
}

Point::showPoint()
{
    cout<<"("<<x<<","<<y<<")"<<endl;
}
