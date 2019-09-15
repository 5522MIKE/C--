#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED
#include"Point.h"

class Line{
public:
    Line(Point &p3,Point &p4)
    {
    x1 = p3.getX();
    y1 = p3.getY();
    x2 = p4.getX();
    y2 = p4.getY();
    }
    friend float angle(Line &line1, Line &line2);
private:
    int x1,y1,x2,y2;
};


#endif // LINE_H_INCLUDED
