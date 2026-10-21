#include <iostream>
#include <clocale>
#include "Fraction.h"

using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF-8");
    cout << "--- Тест класса Fraction ---" << endl;

    Fraction f1;
    Fraction f2(3, 4);
    Fraction f3(5);

    cout << "f1 = "; f1.print(); cout << endl;
    cout << "f2 = "; f2.print(); cout << endl;
    cout << "f3 = "; f3.print(); cout << endl;
    cout << "Всего объектов: " << Fraction::getObjectCount() << endl;

    return 0;
}