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
    static int totalOperations; // Счетчик операций
    static int destroyedCount; // Счетчик удаленных

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
    static int getTotalOperations();
    static void resetTotalOperations();
    static int getDestroyedCount();

    // Вывод
    void print() const;
    void printHistory() const;
    void addHistoryEntry(const string& entry) const;

    // Унарные операторы
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);

    // Арифметическое присваивание
    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);

    // Бинарные арифметические
    friend Fraction operator+(Fraction lhs, const Fraction& rhs);
    friend Fraction operator-(Fraction lhs, const Fraction& rhs);
    friend Fraction operator*(Fraction lhs, const Fraction& rhs);
    friend Fraction operator/(Fraction lhs, const Fraction& rhs);

    // Сравнения
    friend bool operator<(const Fraction& a, const Fraction& b);
    friend bool operator>(const Fraction& a, const Fraction& b);
    friend bool operator<=(const Fraction& a, const Fraction& b);
    friend bool operator>=(const Fraction& a, const Fraction& b);
    friend bool operator==(const Fraction& a, const Fraction& b);
    friend bool operator!=(const Fraction& a, const Fraction& b);
};

#endif