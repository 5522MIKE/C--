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
			cout<<"������"<<name<<endl;
			cout<<"ѧ�ţ�"<<xue<<endl;
			cout<<"���䣺"<<age<<endl;
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
	cout<<"������ѧ����������";
	cin>>n;
	cout<<"������ѧ����ѧ�ţ�";
	cin>>x;
	cout<<"������ѧ�������䣺";
	cin>>a;
	stu.setStudent(n,x,a);
	stu.showStudent();
}
