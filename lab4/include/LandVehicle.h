#ifndef LANDVEHICLE_H
#define LANDVEHICLE_H

#include "Vehicle.h"

/**
 * @class LandVehicle
 * @brief Промежуточный класс наземного транспорта.
 * 
 * Наследует Vehicle с использованием виртуального наследования (virtual public),
 * что впоследствии решает проблему ромбовидного наследования (diamond problem).
 */
class LandVehicle : virtual public Vehicle {
protected:
    int wheels;    ///< Количество колёс
    double mass;   ///< Масса транспортного средства (в тоннах)

public:
    /**
     * @brief Конструктор наземного транспорта
     * @param b Марка
     * @param w Количество колёс
     * @param m Масса
     */
    LandVehicle(string b, int w, double m);

    /// @brief Конструктор копирования
    LandVehicle(const LandVehicle& other);

    /// @brief Оператор присваивания
    LandVehicle& operator=(const LandVehicle& other);

    /// @brief Виртуальный деструктор
    virtual ~LandVehicle();

    /// @brief Переопределённый вывод информации
    void printInfo() const override;
};

#endif