/**
 * @file main.cpp
 * @brief Демонстрация работы класса Fraction
 */

#include <iostream>
#include <clocale>
#include "Fraction.h"

using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF-8");

    cout << "---- Тест класса Fraction ----" << endl;

    // Создание объектов
    cout << "-- Создание объектов --" << endl;
    Fraction f1;          // по умолчанию: 0/1
    Fraction f2(3, 4);    // параметризованный: 3/4
    Fraction f3(5);       // explicit: 5/1
    cout << "f1 = "; f1.print(); cout << endl;
    cout << "f2 = "; f2.print(); cout << endl;
    cout << "f3 = "; f3.print(); cout << endl;
    cout << "Всего операций после создания: " << Fraction::getTotalOperations() << endl;
    cout << endl;

    // Унарные операторы
    cout << "-- Унарные операторы --" << endl;
    Fraction u(3, 4);
    cout << "Исходная: "; u.print(); cout << endl;
    cout << "++u = "; (++u).print(); cout << endl;
    cout << "u++ (старое) = "; (u++).print(); cout << endl;
    cout << "После u++: "; u.print(); cout << endl;
    cout << "--u = "; (--u).print(); cout << endl;
    cout << "u-- (старое)= "; (u--).print(); cout << endl;
    cout << "После u--: "; u.print(); cout << endl;
    cout << endl;

    // Арифметическое присваивание
    cout << "-- Арифметическое присваивание --" << endl;
    Fraction a(1, 2), b(1, 3);
    a += b; cout << "1/2 += 1/3 = "; a.print(); cout << endl;
    a -= b; cout << "5/6 -= 1/3 = "; a.print(); cout << endl;
    a *= b; cout << "1/2 *= 1/3 = "; a.print(); cout << endl;
    a /= b; cout << "1/6 /= 1/3 = "; a.print(); cout << endl;
    cout << endl;

    // Бинарные арифметические
    cout << "-- Бинарные арифметические --" << endl;
    Fraction x(1, 2), y(1, 3);
    cout << "1/2 + 1/3 = "; (x + y).print(); cout << endl;
    cout << "1/2 - 1/3 = "; (x - y).print(); cout << endl;
    cout << "1/2 * 1/3 = "; (x * y).print(); cout << endl;
    cout << "1/2 / 1/3 = "; (x / y).print(); cout << endl;
    cout << endl;

    // Сравнения
    cout << "-- Сравнения --" << endl;
    Fraction c1(1, 2), c2(2, 3), c3(1, 2);
    cout << "1/2 < 2/3: " << (c1 < c2 ? "T" : "F") << endl;
    cout << "1/2 > 2/3: " << (c1 > c2 ? "T" : "F") << endl;
    cout << "1/2 <= 2/3: " << (c1 <= c2 ? "T" : "F") << endl;
    cout << "1/2 >= 2/3: " << (c1 >= c2 ? "T" : "F") << endl;
    cout << "1/2 == 1/2: " << (c1 == c3 ? "T" : "F") << endl;
    cout << "1/2 != 2/3: " << (c1 != c2 ? "T" : "F") << endl;
    cout << endl;

    // explicit
    cout << "-- explicit --" << endl;
    Fraction ex1(5);
    // Fraction ex1 = 5;
    cout << "Fraction ex(5): "; ex1.print(); cout << endl;
    cout << endl;

    // mutable
    cout << "-- mutable --" << endl;
    const Fraction constFrac(3, 4);
    cout << "конст-объект: "; constFrac.print(); cout << endl;
    constFrac.addHistoryEntry("Ручная запись в конст-объект");
    cout << "История конст-объекта:" << endl;
    constFrac.printHistory();
    cout << endl;

    // История операций
    cout << "-- История операций --" << endl;
    u.printHistory();
    cout << endl;

    cout << "Всего операций выполнено: " << Fraction::getTotalOperations() << endl;
    cout << endl;

    cout << "-- Завершение --" << endl;

    cout << "Уничтожено объектов: " << Fraction::getDestroyedCount() << endl;
    
    return 0;
}