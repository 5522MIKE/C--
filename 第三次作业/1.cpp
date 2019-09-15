#include<iostream>
using namespace std;
class Cat{
	public:
		Cat()
		{
			numOfCats++;
		}
		~Cat()
		{
			numOfCats--;
		}
		static void getNumOfCats();
	private:
		static int numOfCats;
};
void Cat::getNumOfCats()
{
    cout<<numOfCats<<endl;
}
int Cat::numOfCats=0;
int main()
{
	Cat a;
	Cat::getNumOfCats();
}
