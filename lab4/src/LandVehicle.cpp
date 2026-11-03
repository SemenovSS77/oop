#include "../include/LandVehicle.h"

LandVehicle::LandVehicle(string b, int w, double m) : Vehicle(b), wheels(w), mass(m) {}

LandVehicle::LandVehicle(const LandVehicle& other) : Vehicle(other), wheels(other.wheels), mass(other.mass) {}

LandVehicle& LandVehicle::operator=(const LandVehicle& other) {
    if (this != &other) {
        Vehicle::operator=(other);
        wheels = other.wheels;
        mass = other.mass;
    }
    return *this;
}

LandVehicle::~LandVehicle() {}

void LandVehicle::printInfo() const {
    Vehicle::printInfo();
    cout << "Колёс: " << wheels << ", Масса: " << mass << " т." << endl;
}