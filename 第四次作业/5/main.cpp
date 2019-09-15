#include <iostream>
#include"Point.h"
#include"Line.h"
using namespace std;

int main()
{
    Point p1(0,0),p2(1,1),p3(1,0);
    Line L1(p1,p2),L2(p1,p2);
    cout<<"¼Ð½ÇµÄÓàÏÒÖµ£º"<<angle(L1,L2)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
