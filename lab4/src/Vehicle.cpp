#include "../include/Vehicle.h"

double Vehicle::maxRegisteredSpeed = 0.0;

Vehicle::Vehicle(string b) : brand(b) {}
Vehicle::~Vehicle() {}

void Vehicle::printInfo() const {
    cout << "Транспортное средство марки: " << brand << endl;
}

double Vehicle::getMaxRegisteredSpeed() {return maxRegisteredSpeed; }
void Vehicle::resetMaxSpeed() {maxRegisteredSpeed = 0.0; }

void Vehicle::updateMaxSpeed(double speed) {
    if (speed > maxRegisteredSpeed) maxRegisteredSpeed = speed;
}

void showVehicleBrand(const Vehicle& v) {
    cout << "[Друг] Марка транспорта: " << v.brand << endl;
}