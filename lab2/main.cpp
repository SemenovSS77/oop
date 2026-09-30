#include <iostream>
#include <clocale>
#include "HotelRoom.h"

using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF-8");

    cout << "===== Тест класса HotelRoom =====" << endl;

    // Создание объектов разными конструкторами 
    cout << "--- Создание объектов ---" << endl;
    HotelRoom room1; // по умолчанию
    HotelRoom room2(305, RoomCategory::Standard, 2500.0); // параметризованный
    HotelRoom room3(701, RoomCategory::Lux, 8000.0, "Петров И. А."); // параметризованный с постояльцем

    cout << endl;

    cout << "Всего объектов: " << HotelRoom::getObjectCount() << endl << endl;

    // Вывод начального состояния
    cout << "--- Начальное состояние ---" << endl;
    room1.print();
    room2.print();
    room3.print();
    cout << endl;

    // Корректные операции
    cout << "--- Корректные операции ---" << endl;
    room2.checkIn("Петров И. А.");
    room2.changePrice(3000.0);
    room2.changeCategory(RoomCategory::Lux);

    room1.checkIn("Сидоров С.С.");
    room1.changePrice(1500.0);

    room3.checkOut();
    room3.changePrice(9000.0);

    cout << endl;

    return 0;
}