#include<iostream>
using namespace std;
class complex{
	public:
		setcomplex(float x,float y)
		{
			real = x;
			imaginary = y;
		}
		complex add(complex c)
		{
			c.real += real;
			c.imaginary += imaginary;
			return c;
		}
		isEqual(complex c)
		{
			if(real==c.real&&imaginary==c.imaginary)
			  cout<<"Y"<<endl;
			else
			  cout<<"N"<<endl;
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
	complex c1,c2,c3;
	int x1,x2,y1,y2;
	cout<<"请输入复数1："<<endl;
	cin>>x1>>y1;
	cout<<"请输入复数2："<<endl;
	cin>>x2>>y2;
	c1.setcomplex(x1,y1);
	c2.setcomplex(x2,y2);
	c1.isEqual(c2);
	c3=c1.add(c2); 
	c3.show();
}
