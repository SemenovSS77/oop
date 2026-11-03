#ifndef ICARGOCARRIER_H
#define ICARGOCARRIER_H

class ICargoCarrier {
public:
    virtual ~ICargoCarrier() = default;
    virtual double getCargoCapacity() const = 0;
};

#endif