#include<iostream>
#include<cmath>
using namespace std;
class Point{
	public:
		Point()
		{
			x=0;y=0;
		}
		Point(float xx,float yy)
		{
			x = xx;
			y = yy;
		}
		float calculate_distance(Point p1)
		{
			return sqrt((x-p1.x)*(x-p1.x)+(y-p1.y)*(y-p1.y));
		}
	private:
		float x,y;	
};
int main()
{
	float x1,x2,y1,y2;
	cout<<"请输入两点坐标：";
	cin>>x1>>y1>>x2>>y2;
	Point p1(x1,y1),p2(x2,y2);
	cout<<p1.calculate_distance(p2)<<endl;
}
