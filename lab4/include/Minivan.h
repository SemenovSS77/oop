#ifndef MINIVAN_H
#define MINIVAN_H

#include "Car.h"
#include "Truck.h"

class Minivan : public Car, public Truck {
private:
    char* extraFeature;

public:
    Minivan(string b, int w, double m, int seats, double cargo, double speed, const char* feature);
    Minivan(const Minivan& other);
    Minivan& operator=(const Minivan& other);
    virtual ~Minivan();

    void startEngine() const override; 
    
    void move() const override;
    string getType() const override;

    void printInfo() const override;
};

#endif