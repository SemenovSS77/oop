#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>

using namespace std;

/**
 * @class Fraction
 * @brief Класс, представляющий рациональное число (дробь) вида numerator/denominator
 */
class Fraction {
private:
    int numerator;                        ///< Числитель
    int denominator;                      ///< Знаменатель
    mutable string* history;              ///< История операций (динамический массив)
    mutable int historySize;              ///< Текущий размер истории
    mutable int historyCapacity;          ///< Вместимость массива
    static int totalOperations;           ///< Общий счётчик выполненных операций
    static int destroyedCount;            ///< Общий счётчик уничтоженных объектов

    /**
     * @brief Приведение дроби к несократимому виду и нормализация знака.
     */
    void normalize();

public:
    // ----- Конструкторы -----
    Fraction();
    Fraction(int num, int den);
    explicit Fraction(int value);

    // ----- Правило трёх (для корректной работы с динамической памятью) -----
    Fraction(const Fraction& other);             ///< Конструктор копирования
    Fraction& operator=(const Fraction& other);  ///< Оператор присваивания

    // ----- Деструктор -----
    ~Fraction();

    // ----- Геттеры -----
    int getNumerator() const;
    int getDenominator() const;
    static int getTotalOperations();
    static void resetTotalOperations();
    static int getDestroyedCount();

    // ----- Вывод -----
    void print() const;
    void printHistory() const;
    void addHistoryEntry(const string& entry) const;

    // ----- Унарные операторы -----
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);

    // ----- Арифметическое присваивание -----
    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);

    // ----- Бинарные арифметические -----
    friend Fraction operator+(Fraction lhs, const Fraction& rhs);
    friend Fraction operator-(Fraction lhs, const Fraction& rhs);
    friend Fraction operator*(Fraction lhs, const Fraction& rhs);
    friend Fraction operator/(Fraction lhs, const Fraction& rhs);

    // ----- Сравнения -----
    friend bool operator<(const Fraction& a, const Fraction& b);
    friend bool operator>(const Fraction& a, const Fraction& b);
    friend bool operator<=(const Fraction& a, const Fraction& b);
    friend bool operator>=(const Fraction& a, const Fraction& b);
    friend bool operator==(const Fraction& a, const Fraction& b);
    friend bool operator!=(const Fraction& a, const Fraction& b);
};

#endif