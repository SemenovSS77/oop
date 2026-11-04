#include "../include/Car.h"

Car::Car(string b, int w, double m, int seats, double speed) : Vehicle(b), LandVehicle(b, w, m), passengerSeats(seats) {
    updateMaxSpeed(speed);
}

Car::Car(const Car& other) : Vehicle(other), LandVehicle(other), passengerSeats(other.passengerSeats) {}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        LandVehicle::operator=(other);
        passengerSeats = other.passengerSeats;
    }
    return *this;
}

Car::~Car() {}

void Car::startEngine() const {cout << "Двигатель легкового авто заведён" << endl;}
void Car::move() const {cout << "Легковое авто едет по дороге" << endl;}
string Car::getType() const {return "Car";}
int Car::getPassengerCapacity() const {return passengerSeats;}

void Car::printInfo() const {
    LandVehicle::printInfo();
    cout << "Мест для пассажиров: " << passengerSeats << endl;
}