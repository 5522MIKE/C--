#include <iostream>

using namespace std;

class Point{
public:
    Point(int x=0,int y=0):x(x),y(y){}
    void setP(int x,int y){
        this->x = x;
        this->y = y;
    }
    Point operator+(const Point &c2) const;
    template<class T>
    void operator=(const T &d) {
        x = d;
        y = d;
    }
    Point operator/(const Point &c2) const;
    void show() const;
private:
    int x,y;
};

Point Point::operator+(const Point&c2) const{
    return Point(x+c2.x,y+c2.y);
}

Point Point::operator/(const Point&c2) const{
    return Point(x/c2.x,y/c2.y);
}
void Point::show() const{
    cout<<"("<<x<<","<<y<<")"<<endl;
}

template<class T>
T avg_array(T *array,int count){
    int i=0;
    T sum=0;
    for(;i < count;i++){
        sum =  sum+array[i];
    }

    T q;
    q=i;
    return  sum/q;
}
int main()
{
    double a[] = {1,7,7,9};
    float b[] = {5,5,5};
    cout<<avg_array(a,4)<<endl;
    cout<<avg_array(b,3)<<endl;

    Point c[3];
    c[0].setP(1,3);
    c[1].setP(3,1);
    c[2].setP(2,2);
    avg_array(c,3).show();
    return 0;
}
