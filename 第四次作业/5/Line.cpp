#include<iostream>
#include<cmath>
#include"Line.h"
using namespace std;


float angle(Line &line1, Line &line2)
{
    float a;
    a = acos(((line1.x1-line1.x2)*(line2.x1-line2.x2)+(line1.y1-line1.y2)*(line2.y1-line2.y2))/(sqrt(pow(line1.x1-line1.x2,2)+pow(line1.y1-line1.y2,2))*sqrt(pow(line2.x1-line2.x2,2)+pow(line2.y1-line2.y2,2))));

    return a;
}
