#include "HotelRoom.h"
#include <iostream>

using namespace std;

// Инициализация статического счетчика
int HotelRoom::objectCount = 0;

// Конструктор по умолчанию
HotelRoom::HotelRoom() :
    number(1),
    category(RoomCategory::Economy),
    pricePerNight(1000.0),
    isOccupied(false),
    guestName("")
{
    objectCount++;
    cout << "[HotelRoom] Создан номер по умолчанию №" << number << endl;
}

// Параметризованный конструктор со списком инициализации 
HotelRoom::HotelRoom(int number, RoomCategory category, double pricePerNight) :
    number(number),
    category(category),
    pricePerNight(pricePerNight),
    isOccupied(false),
    guestName("")
    // Проверка корректности входных данных
{
    if (this->number <= 0) this->number = 1;
    if (this->pricePerNight < 0) this->pricePerNight = 0.0;

    objectCount++;
    cout << "[HotelRoom] Создан номер №" << this->number << endl;
}

// Параметризованный конструктор. Сразу с гостем
HotelRoom::HotelRoom(int number, RoomCategory caterogy, double pricePerNight, const string& guestName) :
    number(number),
    category(category),
    pricePerNight(pricePerNight),
    isOccupied(!guestName.empty()),
    guestName(guestName)
{
    if (this->number <= 0) this->number = 1;
    if (this->pricePerNight < 0) this->pricePerNight = 0.0;

    objectCount++;
    cout << "[HotelRoom] Создан номер №" << this->number;
    if (this->isOccupied) cout << " - заселен: " << this->guestName;
    cout << endl;
}

// Деструктор
HotelRoom::~HotelRoom() {
    objectCount--;
    cout << "[HotelRoom] Уничтожен номер №" << number << " (осталось объектов: " << objectCount << ")" << endl;
}

// Методы чтения
int HotelRoom::getNumber() const {return number;}
RoomCategory HotelRoom::getCategory() const {return category;}
double HotelRoom::getPricePerNight() const {return pricePerNight;}
bool HotelRoom::isOccupiedStatus() const {return isOccupied;}
string HotelRoom::getGuestName() const {return guestName;}
int HotelRoom::getObjectCount() {return objectCount;}

string HotelRoom::categoryToString(RoomCategory cat) {
    switch (cat) {
        case RoomCategory::Economy: return "Эконом";
        case RoomCategory::Standard: return "Стандарт";
        case RoomCategory::Lux: return "Люкс";
        case RoomCategory::President: return "Президентский";
    }
    return "Неизвестно";
}