#include<iostream>
#include<cmath>
using namespace std;
bool prime(int a)
{
	int i;
	for(i=2;i<sqrt(a);i++)
	{
		if(a/i==0)
			return false;
	}
	return true;
}
void gotbaha(int x)
{
	int i,j;
	for(i=3;i<sqrt(x);i++)
	{
		if(prime(i))
		{
			if(prime(x-i))
			{
				cout<<x<<"="<<i<<"+"<<x-i<<endl;
				break;
			}
		}
	}
	if(i>=sqrt(x))
		cout<<"���Ϊ��ΰ��Ŀ�ѧ��"<<endl; 
	else
		return ;
}
int main()
{
	int a;
	cin>>a;
	gotbaha(a);
}
