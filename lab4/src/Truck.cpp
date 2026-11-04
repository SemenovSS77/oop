#include "../include/Truck.h"

Truck::Truck(string b, int w, double m, double cargo, double speed) : Vehicle(b), LandVehicle(b, w, m), cargoCapacity(cargo) {
    updateMaxSpeed(speed);
}

Truck::Truck(const Truck& other) : Vehicle(other), LandVehicle(other), cargoCapacity(other.cargoCapacity) {}

Truck& Truck::operator=(const Truck& other) {
    if (this != &other) {
        LandVehicle::operator=(other);
        cargoCapacity = other.cargoCapacity;
    }
    return *this;
}

Truck::~Truck() {}

void Truck::startEngine() const {cout << "Двигатель грузовика заведён" << endl;}
void Truck::move() const {cout << "Грузовик едет с грузом" << endl;}
string Truck::getType() const {return "Truck";}
double Truck::getCargoCapacity() const {return cargoCapacity;}

void Truck::printInfo() const {
    LandVehicle::printInfo();
    cout << "Грузоподъёмность: " << cargoCapacity << " т." << endl;
}