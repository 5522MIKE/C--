#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
class Point{
public:
    friend class Line;
    Point(int x=0,int y=0):x(x),y(y){}
    resetPoint(int xx,int yy);
    showPoint();
    int getX(){return x;}
    int getY(){return y;}

private:
    int x,y;
};


#endif // POINT_H_INCLUDED
