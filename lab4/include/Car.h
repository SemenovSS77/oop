#ifndef CAR_H
#define CAR_H

#include "LandVehicle.h"
#include "IPassengerCarrier.h"

class Car : virtual public LandVehicle, public IPassengerCarrier {
protected:
    int passengerSeats;

public:
    Car(string b, int w, double m, int seats, double speed);
    Car(const Car& other);
    Car& operator=(const Car& other);
    virtual ~Car();

    void startEngine() const override;
    void move() const override;
    string getType() const override;
    int getPassengerCapacity() const override;

    void printInfo() const override;
};

#endif