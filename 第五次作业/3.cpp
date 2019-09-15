#include<iostream>
using namespace std;
class vehicle
{
public:
    vehicle():wheels(0),weight(0){}
    void setvehicle(float x=0,float y=0)
    {
        wheels=x;
        weight=y;
    }
    float getwheels()const
    {
        return wheels;
    }
    float getweight()const
    {
        return weight;
    }
private:
    float wheels,weight;
};
class car:public vehicle
{
public:
    car():passenger_load(0){}
    void setcar(float a,float b,float c)
    {
        setvehicle(a,b);
        passenger_load=c;
    }
    float getpassenger_load()
    {
        return passenger_load;
    }
private:
    float passenger_load;
};
class truck:public vehicle
{
public:
    truck():passenger_load(0),payload(0)
    {
    }
    void settruck(float a,float b,float c,float d)
    {
        setvehicle(a,b);
        passenger_load=c;
        payload=d;
    }
    float getpassenger_load()
    {
        return passenger_load;
    }
    float getpayload()
    {
        return payload;
    }
private:
    float passenger_load,payload;
};
int main()
{
    car a;
    a.setcar(1,2,6);
    truck b;
    b.settruck(1,2,3,5);
    vehicle c;
    c.setvehicle(7,8);
    cout<<a.getweight()<<" "<<a.getwheels()<<" "<<a.getpassenger_load()<<endl;
    cout<<b.getweight()<<" "<<b.getwheels()<<" "<<b.getpassenger_load()<<" "<<b.getpayload()<<endl;
    cout<<c.getweight()<<" "<<c.getwheels()<<" "<<endl;
    return 0;
}
