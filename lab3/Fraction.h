#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Fraction {
private:
    int numerator; // Числитель
    int denominator; // Знаменатель
    mutable vector<string> history; // История операций
    static int objectCount; // Счетчик объектов

    void normalize();

public:
    // Конструкторы
    Fraction();
    Fraction(int num, int den);
    explicit Fraction(int value);

    // Деструктор
    ~Fraction();

    // Геттеры
    int getNumerator() const;
    int getDenominator() const;
    static int getObjectCount();

    // Вывод
    void print() const;
    void printHistory() const;

    // Унарные операторы
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);
};

#endif