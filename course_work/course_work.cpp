#include <iostream>
#include <vector>

using namespace std;

enum class Body_type{sedan,station_wagon,convertible};

ostream& operator << (ostream& o,const Body_type bt)
{
    switch(bt)
    {
        case Body_type::sedan:
            o << "sedan";break;
        case Body_type::station_wagon:
            o << "station_wagon";break;
        case Body_type::convertible:
            o << "convertible";break;
    }
    return o;
}

class Vehicle
{
public:
    double average_speed()
    {
        double average_speed;
        average_speed = S/T;
        return average_speed;
    }
    double fuel_consumption()
    {
        double fuel_consumption;
        fuel_consumption = (fuel/S) * 100;
        return fuel_consumption;
    }
    virtual void info()
    {
        cout<<"weight - "<<weight<<endl;
        cout<<"max_speed - "<<max_speed<<endl;
        cout<<"average_speed - "<<average_speed()<<endl;
        cout<<"fuel_consumption - "<<fuel_consumption()<<endl;
    }
    // virtual void comfort() = 0;
protected:
    int weight;
    int max_speed;
    double S;//путь в км
    int T;//время
    double fuel;//потрачено топлива  в литрах
    Vehicle()
    {
        weight = 2135;
        max_speed = 250;
        S = 100;
        T = 60;
        fuel = 12;
    }
    Vehicle(int weight,int max_speed,double S,int T,double fuel)
    {
        this->weight = weight;
        this->max_speed = max_speed;
        this->S = S;
        this->T = T;
        this->fuel = fuel;
    }
};

class Car:public Vehicle
{
public:
    Car(): Vehicle(){}
    Car(int weight,int max_speed,double S,int T,double fuel)
    :Vehicle(weight,max_speed,S,T,fuel){}
    void info() override
    {
        Vehicle::info();
        cout<<"Body_type - "<<Get_Body_type();
    }
    Car(Body_type);
    Body_type Get_Body_type()const{return body_type;};
private:
    Body_type body_type;
};

Car::Car(Body_type bt) :body_type(bt){}

class Bus:public Vehicle
{
    
};

int main()
{
    double S,fuel;
    int weight,max_speed,T;
    cin>>weight>>max_speed>>S>>T,fuel;
    Car car(Body_type::station_wagon);
    car.info();
    
    return 0;
}