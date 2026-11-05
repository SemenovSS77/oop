#ifndef MINIVAN_H
#define MINIVAN_H

#include "Car.h"
#include "Truck.h"

/**
 * @class Minivan
 * @brief Класс минивэна (демонстрация ромбовидного наследования).
 * 
 * Наследует одновременно Car и Truck, которые оба виртуально наследуют LandVehicle.
 * Содержит динамический ресурс (char*), поэтому реализует глубокое копирование.
 */
class Minivan : public Car, public Truck {
private:
    char* extraFeature;  ///< Динамическая строка с особенностью (требует глубокого копирования)

public:
    /**
     * @brief Конструктор минивэна
     * @param b Марка
     * @param w Колёса
     * @param m Масса
     * @param seats Места для пассажиров
     * @param cargo Грузоподъёмность
     * @param speed Скорость
     * @param feature Особенность (строка)
     */
    Minivan(string b, int w, double m, int seats, double cargo, double speed, const char* feature);

    /// @brief Конструктор копирования (глубокое копирование)
    Minivan(const Minivan& other);

    /// @brief Оператор присваивания (глубокое копирование)
    Minivan& operator=(const Minivan& other);

    /// @brief Деструктор (освобождает динамическую память)
    virtual ~Minivan();

    /// @brief Явное переопределение во избежание неоднозначности от Car и Truck
    void startEngine() const override; 
    
    void move() const override;
    string getType() const override;

    void printInfo() const override;
};

#endif