#include "../include/Minivan.h"
#include <cstring>

Minivan::Minivan(string b, int w, double m, int seats, double cargo, double speed, const char* feature)
    :   Vehicle(b),              // Инициализация виртуальной базы
        LandVehicle(b, w, m),    // Инициализация виртуальной базы
        Car(b, w, m, seats, speed),
        Truck(b, w, m, cargo, speed) {
            extraFeature = new char[strlen(feature) + 1];
            strcpy(extraFeature, feature);
            updateMaxSpeed(speed);
}

Minivan::Minivan(const Minivan& other)
    :   Vehicle(other), 
        LandVehicle(other), 
        Car(other), 
        Truck(other) {
            extraFeature = new char[strlen(other.extraFeature) + 1];
            strcpy(extraFeature, other.extraFeature);
}

Minivan& Minivan::operator=(const Minivan& other) {
    if (this != &other) {
        Car::operator=(other);
        Truck::operator=(other);
        
        delete[] extraFeature;
        extraFeature = new char[strlen(other.extraFeature) + 1];
        strcpy(extraFeature, other.extraFeature);
    }
    return *this;
}

Minivan::~Minivan() {
    delete[] extraFeature;
}

void Minivan::startEngine() const {
    cout << "Двигатель минивэна заведён" << endl;
}

void Minivan::move() const {
    cout << "Минивэн плавно едет по шоссе" << endl;
}

string Minivan::getType() const { return "Minivan"; }

void Minivan::printInfo() const {
    Car::printInfo();
    cout << "Грузоподъёмность (багажник): " << getCargoCapacity() << " т." << endl;
    cout << "Особенность: " << extraFeature << endl;
}