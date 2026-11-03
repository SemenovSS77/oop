#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>

using namespace std;

class Vehicle {
protected:
    string brand;
    static double maxRegisteredSpeed;

public:
    Vehicle(string b);
    virtual ~Vehicle();

    virtual void startEngine() const = 0;
    virtual void move() const = 0;
    virtual string getType() const = 0;

    virtual void printInfo() const;

    static double getMaxRegisteredSpeed();
    static void resetMaxSpeed();
    static void updateMaxSpeed(double speed);

    friend void showVehicleBrand(const Vehicle& v);
};

#endif