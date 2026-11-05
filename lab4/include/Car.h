#ifndef CAR_H
#define CAR_H

#include "LandVehicle.h"
#include "IPassengerCarrier.h"

/**
 * @class Car
 * @brief Класс легкового автомобиля.
 * 
 * Наследует наземный транспорт (виртуально) и реализует интерфейс перевозки пассажиров.
 */
class Car : virtual public LandVehicle, public IPassengerCarrier {
protected:
    int passengerSeats;  ///< Количество мест для пассажиров

public:
    /**
     * @brief Конструктор легкового автомобиля
     * @param b Марка
     * @param w Колёса
     * @param m Масса
     * @param seats Количество мест
     * @param speed Максимальная скорость (для обновления глобальной статики)
     */
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