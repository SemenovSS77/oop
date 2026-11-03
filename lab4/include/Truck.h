#ifndef TRUCK_H
#define TRUCK_H

#include "LandVehicle.h"
#include "ICargoCarrier.h"

class Truck : virtual public LandVehicle, public ICargoCarrier {
protected:
    double cargoCapacity;

public:
    Truck(string b, int w, double m, double cargo, double speed);
    Truck(const Truck& other);
    Truck& operator=(const Truck& other);
    virtual ~Truck();

    void startEngine() const override;
    void move() const override;
    string getType() const override;
    double getCargoCapacity() const override;

    void printInfo() const override;
};

#endif