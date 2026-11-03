#include "../include/Minivan.h"
#include <cstring>

Minivan::Minivan(string b, int w, double m, int seats, double cargo, double speed, const char* feature)
    :   Vehicle(b),
        LandVehicle(b, w, m),
        Car(b, w, m, seats, speed),
        smallCargoCapacity(cargo) {
            extraFeature = new char[strlen(feature) + 1];
            strcpy(extraFeature, feature);
}

Minivan::Minivan(const Minivan& other)
    :   Vehicle(other), LandVehicle(other), Car(other), ICargoCarrier(other),
        smallCargoCapacity(other.smallCargoCapacity) {
            extraFeature = new char[strlen(other.extraFeature) + 1];
            strcpy(extraFeature, other.extraFeature);
}

Minivan& Minivan::operator=(const Minivan& other) {
    if (this != &other) {
        Car::operator=(other);
        smallCargoCapacity = other.smallCargoCapacity;

        delete[] extraFeature;
        extraFeature = new char[strlen(other.extraFeature) + 1];
        strcpy(extraFeature, other.extraFeature);
    }
    return *this;
}

Minivan::~Minivan() {
    delete[] extraFeature;
}

void Minivan::move() const {
    cout << "Минивэн плавно едет по шоссе" << endl;
}

string Minivan::getType() const {return "Minivan";}
double Minivan::getCargoCapacity() const {return smallCargoCapacity;}

void Minivan::printInfo() const {
    Car::printInfo();
    cout << "Багажник: " << smallCargoCapacity << " т." << endl;
    cout << "Особенность: " << extraFeature << endl;
}