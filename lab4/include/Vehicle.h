#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>

using namespace std;

/**
 * @class Vehicle
 * @brief Абстрактный базовый класс, представляющий транспортное средство.
 * 
 * Содержит чисто виртуальные функции, которые обязаны реализовать наследники.
 * Ведет общий статический учет максимальной зарегистрированной скорости.
 */
class Vehicle {
protected:
    string brand;                       ///< Марка транспортного средства
    static double maxRegisteredSpeed;   ///< Статический член: максимальная скорость среди всех объектов

public:
    /**
     * @brief Конструктор базового класса.
     * @param b Марка транспортного средства.
     */
    Vehicle(string b);
    
    /// @brief Виртуальный деструктор для корректного удаления полиморфных объектов.
    virtual ~Vehicle();

    /// @brief Чисто виртуальная функция запуска двигателя.
    virtual void startEngine() const = 0;
    
    /// @brief Чисто виртуальная функция движения.
    virtual void move() const = 0;
    
    /// @brief Чисто виртуальная функция получения типа объекта.
    /// @return Строка с названием типа (например, "Car").
    virtual string getType() const = 0;

    /**
     * @brief Виртуальная функция вывода информации с реализацией по умолчанию.
     * Выводит марку транспортного средства.
     */
    virtual void printInfo() const;

    /// @brief Получить максимальную зарегистрированную скорость.
    static double getMaxRegisteredSpeed();
    
    /// @brief Сбросить статический счетчик максимальной скорости в 0.
    static void resetMaxSpeed();
    
    /**
     * @brief Обновить максимальную скорость, если новая больше текущей.
     * @param speed Проверяемая скорость.
     */
    static void updateMaxSpeed(double speed);

    /**
     * @brief Дружественная функция для вывода марки (демонстрация friend).
     * @param v Ссылка на транспортное средство.
     */
    friend void showVehicleBrand(const Vehicle& v);
};

#endif