#include<iostream>
using namespace std;
class Boat;
class Cat{
	public:
		Cat():weight(0){};
		Cat(int w):weight(w){};
		friend int getTotalWeight(const Cat&,const Boat&);
	private:
		int weight;
};
class Boat{
	public:
		Boat():weight(0){};
		Boat(int w):weight(w){};
		friend int getTotalWeight(const Cat&,const Boat&);
	private:
		int weight;
};
int getTotalWeight(const Cat& c1,const Boat& b1)
{
	return (c1.weight+b1.weight);
}
int main()
{
	Cat cat(10);
	Boat boat(100);
	cout<<getTotalWeight(cat,boat)<<endl;
}
