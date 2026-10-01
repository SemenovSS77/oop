#include "HotelRoom.h"
#include <iostream>

using namespace std;

/// @brief Инициализация статического счётчика объектов
int HotelRoom::objectCount = 0;

/**
 * @brief Конструктор по умолчанию
 * @details Инициализирует номер значениями: №1, Economy, 1000.0, свободен
 */
HotelRoom::HotelRoom() :
    number(1),
    category(RoomCategory::economy()),
    pricePerNight(1000.0),
    isOccupied(false),
    guestName("")
{
    objectCount++;
    cout << "[HotelRoom] Создан номер по умолчанию №" << number << endl;
}

/**
 * @brief Параметризованный конструктор (свободный номер)
 * @param number Номер комнаты
 * @param category Категория
 * @param pricePerNight Цена за сутки
 * @note Некорректные значения (number <= 0, price < 0) корректируются
 *       к допустимым без выброса исключений
 */
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

/**
 * @brief Параметризованный конструктор (занятый номер)
 * @param number Номер комнаты
 * @param category Категория
 * @param pricePerNight Цена за сутки
 * @param guestName Имя гостя. Если не пустое — номер сразу занят
 */
HotelRoom::HotelRoom(int number, RoomCategory category, double pricePerNight, const string& guestName) :
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

/// @brief Деструктор. Уменьшает счётчик объектов и печатает об этом в консоль
HotelRoom::~HotelRoom() {
    objectCount--;
    cout << "[HotelRoom] Уничтожен номер №" << number << " (осталось объектов: " << objectCount << ")" << endl;
}

/// @brief Получить номер комнаты
int HotelRoom::getNumber() const {return number;}

/// @brief Получить категорию номера
RoomCategory HotelRoom::getCategory() const {return category;}

/// @brief Получить цену за сутки
double HotelRoom::getPricePerNight() const {return pricePerNight;}

/// @brief Узнать, занят ли номер
bool HotelRoom::isOccupiedStatus() const {return isOccupied;}

/// @brief Получить имя гостя (пусто, если номер свободен)
string HotelRoom::getGuestName() const {return guestName;}

/**
 * @brief Получить текущее количество существующих объектов
 * @return Число живых экземпляров HotelRoom
 */
int HotelRoom::getObjectCount() {return objectCount;}

/**
 * @brief Преобразовать категорию в строку
 * @param cat Категория номера
 * @return Строковое представление категории
 * @retval "Эконом"          для RoomCategory::Economy
 * @retval "Стандарт"        для RoomCategory::Standard
 * @retval "Люкс"            для RoomCategory::Lux
 * @retval "Президентский"   для RoomCategory::President
 * @retval "Неизвестно"      для некорректного значения
 */
string HotelRoom::categoryToString(RoomCategory cat) {
    return cat.toString();
}

/**
 * @brief Заселить гостя в номер
 * @param name Имя гостя
 * @return true при успехе; false если name пустое или номер занят
 * @warning При ошибке сообщение выводится в консоль
 */
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

/**
 * @brief Выселить гостя
 * @return true при успехе; false если номер и так свободен
 */
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

/**
 * @brief Изменить цену за сутки
 * @param newPrice Новая цена (>= 0)
 * @return true при успехе; false если newPrice < 0
 */
bool HotelRoom::changePrice(double newPrice) {
    if (newPrice < 0) {
        cerr << "Ошибка. Цена не может быть отрицательной" << endl;
        return false;
    }

    pricePerNight = newPrice;
    cout << "Номер №" << number << ": новая цена = " << pricePerNight << endl;
    return true;
}

/**
 * @brief Изменить категорию номера
 * @param newCategory Новая категория
 * @return Всегда true
 */
bool HotelRoom::changeCategory(RoomCategory newCategory) {
    category = newCategory;
    cout << "Номер №" << number << ": новая категория = " << categoryToString(category) << endl;
    return true;
}

/**
 * @brief Проверка инвариантов состояния
 * @return true, если все поля согласованы
 * @details Проверяет: number > 0, price >= 0, согласованность
 *          isOccupied и guestName.
 */
bool HotelRoom::isStateValid() const {
    if (number <= 0) return false;
    if (pricePerNight < 0) return false;
    if (isOccupied && guestName.empty()) return false;
    if (!isOccupied && !guestName.empty()) return false;

    return true;
}

/// @brief Вывести состояние номера в консоль
void HotelRoom::print() const {
    cout << "----- Номер №" << number << " -----" << endl;
    cout << "  Категория: " << categoryToString(category) << endl;
    cout << "  Цена за сутки: " << pricePerNight << endl;
    cout << "  Занят: " << (isOccupied ? "да" : "нет") << endl;
    if (isOccupied) cout << "  Гость: " << guestName << endl;
    cout << "  Состояние: " << (isStateValid() ? "корректно" : "некорректно") << endl;
}