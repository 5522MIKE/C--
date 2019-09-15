#include<iostream>
#include<cassert>
using namespace std;
class point
{
public:
    point():x(0),y(0)
    {
        cout<<"Default Constructor called."<<endl;
    }
    point(int x,int y):x(x),y(y)
    {
        cout<<"Constructor called."<<endl;
    }
    ~point()
    {
        cout<<"Destructor called."<<endl;
    }
    int getx()const{return x;}
    int gety()const{return y;}
    void move (int newx,int newy)
    {
        x=newx;
        y=newy;
    }
private:
    int x,y;
};
class ArrayOfpoints
{
public:
    ArrayOfpoints(int size):size(size)
    {
        points=new point[size];
    }
    ~ArrayOfpoints()
    {
        cout<<"Deleting..."<<endl;
        delete[]points;
    }
    point &element(int index)
    {
        assert(index>=0&&index<size);
        return points[index];
    }
    ArrayOfpoints(const ArrayOfpoints &v);
private:
    point*points;
    int size;
};
ArrayOfpoints::ArrayOfpoints(const ArrayOfpoints &v)
{
    size=v.size;
    points=new point[size];
    for(int i=0;i<size;i++)
    {
        points[i]=v.points[i];
    }
}
int main()
{
    int count;
    cout<<"Please enter the count of points:";
    cin>>count;
    ArrayOfpoints pointsArray1(count);
    pointsArray1.element(0).move(5,10);
    pointsArray1.element(1).move(15,20);
    ArrayOfpoints pointsArray2=pointsArray1;
    cout<<"Copy of pointsArray1:"<<endl;
    cout<<"point_0 of array2:"<<pointsArray2.element(0).getx()<<","<<pointsArray2.element(0).gety()<<endl;
    cout<<"point_1 of array2:"<<pointsArray2.element(1).getx()<<","<<pointsArray2.element(1).gety()<<endl;
    pointsArray1.element(0).move(25,30);
    pointsArray1.element(1).move(35,40);
    cout<<"After the moving of pointsArray1:"<<endl;
    cout<<"Point_0 of array2:"<<pointsArray2.element(0).getx()<<","<<pointsArray2.element(0).gety()<<endl;
    cout<<"Point_1 of array2:"<<pointsArray2.element(1).getx()<<","<<pointsArray2.element(1).gety()<<endl;
    return 0;
}
