/*
 virtual functions which can be a covariant (using pointers)
simple example to envision
 
I am not usung a default constructor, that's why I am initializing constructor from base class in derived one using initializer_list
 
while writing I am using different naming convention just to keep variety

 */

#include <iostream>
using namespace std;


class Damages
{
public:
    string _descOfDamage;
    Damages(string dsc) : _descOfDamage(dsc)
    {}
    Damages(Damages & ref); // copy constructor
    Damages(Damages && mv); // moving constr.
    
};

class DamageTire : public Damages
{
public:
    int _nrOfWheel;
    DamageTire(int wheelNr, string whatH) : Damages(whatH), _nrOfWheel(wheelNr)
    {}
    
    
};

class Vehicle
{
public:
    string _VehType;
    Vehicle(string type) : _VehType(type) {}
    Damages * showCondition();
    
};

class Car : public Vehicle{
    string _carModel;
public:
    Car(string mod, string VehicleType) : Vehicle(VehicleType), _carModel(mod)
    {}
    
};




int main(int argc, const char * argv[]) {
   
    
    
    return 0;
}

Damages::Damages(Damages & ref)
{
    this->_descOfDamage = ref._descOfDamage;
}

Damages::Damages(Damages && mv)
{
    this->_descOfDamage = mv._descOfDamage;
}

Damages * Vehicle::showCondition()
{
    
    DamageTire * ptrOnTire = new DamageTire(1, "tire exploded on the way to the work");
    /*
     using virtual function combined with a pointer we can return pointer which point on derived object
     */
    
    return ptrOnTire;
}
