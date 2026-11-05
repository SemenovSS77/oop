#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>

using namespace std;

/**
 * @file Vehicle.h
 * @brief Заголовочный файл абстрактного базового класса Vehicle.
 */

/**
 * @class Vehicle
 * @brief Абстрактный базовый класс, представляющий любое транспортное средство.
 * 
 * Содержит чисто виртуальные функции, которые обязаны реализовать все наследники.
 * Хранит общую статистику в виде максимальной зарегистрированной скорости.
 */
class Vehicle {
protected:
    string brand;                      ///< Марка транспортного средства
    static double maxRegisteredSpeed;  ///< Статическая переменная: макс. скорость среди всех объектов

public:
    /**
     * @brief Конструктор базового класса
     * @param b Марка транспортного средства
     */
    Vehicle(string b);

    /// @brief Виртуальный деструктор
    virtual ~Vehicle();

    /// @brief Чисто виртуальная функция запуска двигателя
    virtual void startEngine() const = 0;

    /// @brief Чисто виртуальная функция движения
    virtual void move() const = 0;

    /**
     * @brief Чисто виртуальная функция получения типа транспорта
     * @return Строка с названием типа
     */
    virtual string getType() const = 0;

    /// @brief Виртуальная функция вывода общей информации (реализация по умолчанию)
    virtual void printInfo() const;

    /// @brief Получить максимальную зарегистрированную скорость
    static double getMaxRegisteredSpeed();

    /// @brief Сбросить максимальную скорость в 0
    static void resetMaxSpeed();

    /**
     * @brief Обновить максимальную скорость, если переданная больше текущей
     * @param speed Скорость нового транспортного средства
     */
    static void updateMaxSpeed(double speed);

    /**
     * @brief Дружественная функция для вывода марки (демонстрация friend)
     * @param v Ссылка на объект Vehicle
     */
    friend void showVehicleBrand(const Vehicle& v);
};

#endif