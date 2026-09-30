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

    // Некорректные операции
    cout << "--- Некорректные операции ---" << endl;
    room2.checkIn("Кто-то ещё");
    room1.checkIn("");
    room1.checkOut();
    room1.checkOut();
    room2.changePrice(-500.0);

    cout << endl;

    // Повторный вывод. Состояние должно остаться корректным
    cout << "--- Состояние после всех операций ---" << endl;
    room1.print();
    room2.print();
    room3.print();
    cout << endl;

    // Проверка независимости объектов
    cout << "--- Проверка независимости объектов ---" << endl;
    cout << "До изменения room1:" << endl;
    cout << " room2.getPricePerNight() = " << room2.getPricePerNight() << endl;
    cout << " room3.getPricePerNight() = " << room3.getPricePerNight() << endl;

    // Меняем только room1
    room1.changePrice(99999.0);

    cout << "После изменения room1 (room1 = 99999):" << endl;
    cout << " room1.getPricePerNight() = " << room1.getPricePerNight() << endl;
    cout << " room2.getPricePerNight() = " << room2.getPricePerNight() << "<- не изменилось" << endl;
    cout << " room3.getPricePerNight() = " << room3.getPricePerNight() << "<- не изменилось" << endl;

    cout << endl;

    cout << "--- Завершение программы. Вызов деструкторов ---" << endl;

    return 0;
}