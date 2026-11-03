#ifndef IPASSENGERCARRIER_H
#define IPASSENGERCARRIER_H

class IPassengerCarrier {
public:
    virtual ~IPassengerCarrier() = default;
    virtual int getPassengerCapacity() const = 0;
};

#endif