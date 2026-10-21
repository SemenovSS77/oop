#include <iostream>
#include <clocale>
#include "Fraction.h"

using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF-8");
    cout << "--- Тест класса Fraction ---" << endl;

    cout << "-- Создание объектов --" << endl;
    Fraction f1;
    Fraction f2(3, 4);
    Fraction f3(5);
    cout << "f1 = "; f1.print(); cout << endl;
    cout << "f2 = "; f2.print(); cout << endl;
    cout << "f3 = "; f3.print(); cout << endl;
    cout << "Всего объектов: " << Fraction::getObjectCount() << endl;

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

    cout << "-- Арифметическое присваивание --" << endl;
    Fraction a(1, 2), b(1, 3);
    a += b; cout << "1/2 += 1/3 = "; a.print(); cout << endl;
    a -= b; cout << "5/6 -= 1/3 = "; a.print(); cout << endl;
    a *= b; cout << "1/2 *= 1/3 = "; a.print(); cout << endl;
    a /= b; cout << "1/6 /= 1/3 = "; a.print(); cout << endl;
    cout << endl;

    return 0;
}