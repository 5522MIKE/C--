#include"point.h"
#include <iostream>

using namespace std;

int main()
{
    Point a(4,5);
    cout<<"Point a:"<<a.getX()<<","<<a.getY()<<endl;
    Point::showCount();

    Point b(a);
    cout<<"Point b:"<<b.getX()<<","<<b.getY()<<endl;
    Point::showCount();

    return 0;
}
