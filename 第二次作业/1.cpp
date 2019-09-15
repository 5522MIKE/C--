#include<iostream>
#include<string>
using namespace std;
class student{
	public:
		setStudent(string n,long long x,int a)
		{
			name = n;
			xue = x;
			age = a;
		}
		showStudent()
		{
			cout<<"姓名："<<name<<endl;
			cout<<"学号："<<xue<<endl;
			cout<<"年龄："<<age<<endl;
		}
	private:
		int age;
		long long xue;
		string name;	
};
int main()
{
	string n;
	long long x;
	int a;
	student stu;
	cout<<"请输入学生的姓名：";
	cin>>n;
	cout<<"请输入学生的学号：";
	cin>>x;
	cout<<"请输入学生的年龄：";
	cin>>a;
	stu.setStudent(n,x,a);
	stu.showStudent();
}
