#include<iostream>
#include<string>
using namespace std;
class student{
	public:
		student(string name,int mark):name(name),mark(mark){}
		friend student compare(const student &,const student &);
		static void show(const student &s1)
		{
			cout<<s1.name<<endl;
		}
	private:
		string name;
		int mark;
};
student compare(const student &s1,const student &s2)
{
	if(s1.mark>s2.mark)
		return s1;
	else if(s1.mark<s2.mark)
		return s2;
}
int main()
{
	string yym,ldw;
	student s1(yym,100),s2(ldw,99);
	student::show(compare(s1,s2));
}
