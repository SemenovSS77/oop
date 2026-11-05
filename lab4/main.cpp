/**
 * @file main.cpp
 * @brief Тестирование иерархии классов транспорта.
 * 
 * Читает данные из файла, демонстрирует полиморфизм, статические члены,
 * работу дружественной функции и глубокое копирование при ромбовидном наследовании.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <clocale>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Minivan.h"

using namespace std;

/**
 * @brief Точка входа в программу.
 * @return 0 при успешном выполнении, 1 при ошибке открытия файла.
 */
int main() {
    setlocale(LC_ALL, ".UTF-8");
    cout << "=== Тестирование иерархии транспорта ===" << endl << endl;

    // 1. Чтение данных из файла
    ifstream file("data.txt");
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть data.txt" << endl;
        return 1;
    }

    vector<Vehicle*> vehicles;
    string type, brand, feature;
    int wheels, seats;
    double mass, speed, cargo;

    while (file >> type >> brand >> wheels >> mass >> speed) {
        if (type == "Car") {
            file >> seats;
            vehicles.push_back(new Car(brand, wheels, mass, seats, speed));
        }
        else if (type == "Truck") {
            file >> cargo;
            vehicles.push_back(new Truck(brand, wheels, mass, cargo, speed));
        }
        else if (type == "Minivan") {
            file >> seats >> cargo >> feature;
            vehicles.push_back(new Minivan(brand, wheels, mass, seats, cargo, speed, feature.c_str()));
        }
    }
    file.close();

    // 2. Демонстрация полиморфизма
    cout << "--- 1. Полиморфный вызов ---" << endl;
    for (Vehicle* v : vehicles) {
        v->startEngine();
        v->move();
        v->printInfo();
        cout << "-------------------" << endl;
    }

    // 3. Демонстрация статики и дружественной функции
    cout << endl;
    cout << "--- 2. Статика и френд ---" << endl;
    cout << "Макс. скорость: " << Vehicle::getMaxRegisteredSpeed() << " км/ч" << endl;
    showVehicleBrand(*vehicles[0]);

    // 4. Демонстрация глубокого копирования (Minivan)
    cout << endl;
    cout << "--- 3. Глубокое копирование Minivan ---" << endl;
    Minivan* orig = nullptr;
    for (Vehicle* v : vehicles) {
        if (v->getType() == "Minivan") {
            orig = dynamic_cast<Minivan*>(v);
            break;
        }
    }

    if (orig) {
        Minivan copy(*orig); // Конструктор копирования
        cout << "Оригинал: ";
        orig->printInfo();
        cout << "Копия: ";
        copy.printInfo();

        Minivan assigned("Test", 4, 1.5, 5, 0.5, 150, "Temp");
        assigned = *orig;    // Оператор присваивания
        cout << "После присваивания: ";
        assigned.printInfo();
    }

    // 5. Сброс статики
    cout << endl;
    cout << "--- 4. Сброс статики ---" << endl;
    Vehicle::resetMaxSpeed();
    cout << "После сброса: " << Vehicle::getMaxRegisteredSpeed() << endl;

    // 6. Очистка памяти
    for (Vehicle* v : vehicles) delete v;
    return 0;
}