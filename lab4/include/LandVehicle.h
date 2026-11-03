#ifndef LANDVEHICLE_H
#define LANDVEHICLE_H

#include "Vehicle.h"

class LandVehicle : virtual public Vehicle {
protected:
    int wheels;
    double mass;

public:
    LandVehicle(string b, int w, double m);
    LandVehicle(const LandVehicle& other);
    LandVehicle& operator=(const LandVehicle& other);
    virtual ~LandVehicle();

    void printInfo() const override;
};

#endif