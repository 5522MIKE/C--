#include<iostream>
using namespace std;
class Point{
	public:
	    friend class CReat;
		Point()
		{
			x = 0;
			y = 0;
		}
		Point(int xx,int yy)
		{
			x = xx;
			y = yy;
		}
	private:
	int x,y;
};
class CReat{
	public:
		CReat()
		{
			Point p1,p2;
		}
		RectHeight(const Point p1,const Point p2)
		{
			if(p1.y>=p2.y)
				cout<<p1.y-p2.y<<endl;
			else
				cout<<p2.y-p1.y<<endl;
		}
		RectWidth(const Point p1,const Point p2)
		{
			if(p1.x>=p2.x)
				cout<<p1.x-p2.x<<endl;
			else
				cout<<p2.x-p1.x<<endl;
		}
	private:
		Point p1,p2;
};
int main()
{

}
