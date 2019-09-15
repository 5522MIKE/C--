#include <iostream>

using namespace std;

class Mammal{
public:
    virtual speak();
};
Mammal::speak(){
    cout<<"6"<<endl;
}

class Dog:public Mammal{
public:
    speak();
};
Dog::speak(){
    cout<<"wang! wang! wang!"<<endl;
}

int main()
{
    Dog doggy;
    doggy.speak();
    return 0;
}
