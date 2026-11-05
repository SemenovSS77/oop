#ifndef TRUCK_H
#define TRUCK_H

#include "LandVehicle.h"
#include "ICargoCarrier.h"

/**
 * @class Truck
 * @brief Класс грузового автомобиля.
 * 
 * Наследует наземный транспорт (виртуально) и реализует интерфейс перевозки грузов.
 */
class Truck : virtual public LandVehicle, public ICargoCarrier {
protected:
    double cargoCapacity;  ///< Грузоподъёмность в тоннах

public:
    /**
     * @brief Конструктор грузовика
     * @param b Марка
     * @param w Колёса
     * @param m Масса
     * @param cargo Грузоподъёмность
     * @param speed Максимальная скорость
     */
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