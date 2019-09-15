#include<iostream>
using namespace std;
class complex{
	public:
		complex(float x,float y)
		{
			real = x;
			imaginary = y;
		}
		complex()
		{
			real = 0;
			imaginary = 0;
		}
		complex(complex &c)
		{
			real = c.real;
			imaginary = c.imaginary;
		}
		complex add(complex c)
		{
			c.real += real;
			c.imaginary += imaginary;
			return c;
		}
		bool isEqual(complex c)
		{
			if(real==c.real&&imaginary==c.imaginary)
			  return true;
			else
			  return false;
		}
		show()
		{
			cout<<real<<"+";
			cout<<imaginary<<"i"<<endl;
		}
	private:
	float real, imaginary;
};
int main()
{
	complex c3;
	float x1,x2,y1,y2;
	cout<<"请输入复数1："<<endl;
	cin>>x1>>y1;
	cout<<"请输入复数2："<<endl;
	cin>>x2>>y2;
	complex c1(x1,y1);
	complex c2(x2,y2);
	cout<<c1.isEqual(c2)<<endl;
	c3=c1.add(c2);
	c3.show();
}
// 原题中的main函数不能通过运行
