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

// Методы изменения
bool HotelRoom::checkIn(const string& name) {
    if (name.empty()) {
        cerr << "Ошибка. Имя постояльца не может быть пустым" << endl;
        return false;
    }
    if (isOccupied) {
        cerr << "Ошибка. Номер №" << number << " уже занят" << endl;
        return false;
    }

    isOccupied = true;
    guestName = name;
    cout << "Номер №" << number << " заселен: " << guestName << endl;
    return true;
}

bool HotelRoom::checkOut() {
    if (!isOccupied) {
        cerr << "Ошибка. Номер №" << number << " итак свободен" << endl;
        return false;
    }

    cout << "Номер №" << number << " выселен (был: " << guestName << ")" << endl;
    isOccupied = false;
    guestName = "";
    return true;
}

bool HotelRoom::changePrice(double newPrice) {
    if (newPrice < 0) {
        cerr << "Ошибка. Цена не может быть отрицательной" << endl;
        return false;
    }

    pricePerNight = newPrice;
    cout << "Номер №" << number << ": новая цена = " << pricePerNight << endl;
    return true;
}

bool HotelRoom::changeCategory(RoomCategory newCategory) {
    category = newCategory;
    cout << "Номер №" << number << ": новая категория = " << categoryToString(category) << endl;
    return true;
}

// Вспомогательные методы
bool HotelRoom::isStateValid() const {
    if (number <= 0) return false;
    if (pricePerNight < 0) return false;
    if (isOccupied && guestName.empty()) return false;
    if (!isOccupied && !guestName.empty()) return false;

    return true;
}

void HotelRoom::print() const {
    cout << "----- Номер №" << number << " -----" << endl;
    cout << "  Категория: " << categoryToString(category) << endl;
    cout << "  Цена за сутки: " << pricePerNight << endl;
    cout << "  Занят: " << (isOccupied ? "да" : "нет") << endl;
    if (isOccupied) cout << "  Гость: " << guestName << endl;
    cout << "  Состояние: " << (isStateValid() ? "корректно" : "некорректно") << endl;
}