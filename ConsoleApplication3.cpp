#include <iostream>

using namespace std;

class Car {
public:
    string name;
    int horsePower;

    Car() {}

    Car(string name, int horsePower) {
        this->name = name;
        this->horsePower = horsePower;
    }

    void drive() {
        cout << "Drive" << "\n\n";
    }

    void info() {
        cout << "name: " << name << endl;
        cout << "horsePower: " << horsePower << "\n";


    }

};

class ElectroCar : public Car {
public:
    int charge;

    ElectroCar(string name, int horsePower, int charge) : Car(name, horsePower) {
        this->charge = charge;
    }
   

    void info() {
        Car::info();
        cout << "charge: " << charge << endl;

    }

};



class DvsCar : public Car{
public:
    int fuel;
    DvsCar(string name, int engine, int fuel) : Car(name, horsePower) {
        this->fuel = fuel;
        

    }
    DvsCar(int fuel) {
        this->fuel = fuel;
    }
    void info() {
        Car::info();
        cout << "engineCapacity " << fuel << endl;
       
    }

        
};

class HybridCar : public ElectroCar, public DvsCar {
public:
    HybridCar(string name, int horsePower, int charge, int fuel) :
        
        ElectroCar(name,horsePower,charge),
        DvsCar(fuel){

    }

    void info() {
        cout << ElectroCar::name << endl;
        cout << ElectroCar::horsePower << endl;
        cout << charge << endl;
        cout << fuel << endl;
    }





    


};

int main()
{
    /*Car car1("Car", 700);
    car1.info();
    car1.drive();*/

    ElectroCar electroCar1("eleoctroCar", 400, 1500);
    DvsCar DvsCar1("eqwe", 800, 150);
    


    
    electroCar1.info();
    electroCar1.drive();

    DvsCar1.info();
    DvsCar1.drive();

    HybridCar hybridCar("hybridCar", 400, 2000,100);
    hybridCar.info();

}