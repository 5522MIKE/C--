#include <iostream>
#define PI 3.14

using namespace std;

class Shape{
public:
    virtual getArea() const=0;
    virtual getPerim() const=0;
};

class Rectangle:public Shape{
public:
    virtual getArea() const;
    virtual getPerim() const;
    Rectangle(double x,double y);
private:
    double x,y;
};
Rectangle::Rectangle(double xx,double yy){
    this->x = xx;
    this->y = yy;
}
Rectangle::getArea() const{
    cout<<x*y<<endl;
}
Rectangle::getPerim() const{
    cout<<x+x+y+y<<endl;
}

class Circle:public Shape{
public:
    virtual getArea() const;
    virtual getPerim() const;
    Circle(double r);
private:
    double r;
};
Circle::Circle(double rr){
    this->r = rr;
}
Circle::getArea() const{
    cout<<PI*r*r<<endl;
}
Circle::getPerim() const{
    cout<<2*PI*r<<endl;
}

int main()
{
    Rectangle sq(2,2);
    Circle r(3);
    sq.getArea();
    sq.getPerim();
    r.getArea();
    r.getPerim();
    return 0;
}
