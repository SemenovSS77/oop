#ifndef HOTELROOM_H
#define HOTELROOM_H

#include <string>
using namespace std;

/**
 * @brief Категория гостиничного номера.
 *
 * Пользовательский перечисляемый тип, определяющий уровень комфорта номера
 */

class RoomCategory {
private:
    int code;   ///< 0 - Эконом, 1 - Стандарт, 2 - Люкс, 3 - Президентский

public:
    /**
     * @brief Конструктор с кодом категории
     * @param code Код в диапазоне [0, 3]. Иначе приводится к 0 (Economy)
     */
    RoomCategory(int code) {
        if (code < 0 || code > 3) this->code = 0;
        else this->code = code;
    }

    /**
     * @brief Преобразовать категорию в строку
     * @return "Эконом", "Стандарт", "Люкс" или "Президентский"
     */
    string toString() const {
        switch (code) {
            case 0: return "Эконом";
            case 1: return "Стандарт";
            case 2: return "Люкс";
            case 3: return "Президентский";
        }
        return "Неизвестно";
    }

    /// @brief Фабрики для читаемости 
    static RoomCategory economy() {return RoomCategory(0);}
    static RoomCategory standard() {return RoomCategory(1);}
    static RoomCategory lux() {return RoomCategory(2);}
    static RoomCategory president() {return RoomCategory(3);}
};

/**
 * @class HotelRoom
 * @brief Класс, описывающий гостиничный номер
 *
 * Хранит информацию о номере: номер комнаты, категорию, цену за сутки,
 * статус занятости и имя гостя. Поддерживает операции заселения/выселения,
 * изменения цены и категории. Ведёт подсчёт созданных объектов через
 * статический счётчик
 *
 * @warning Все методы изменения возвращают bool и печатают сообщение об
 *          ошибке при некорректных входных данных. Исключения
 *          не выбрасываются
 */
class HotelRoom {
private:
    int number;                 ///< Номер комнаты (должен быть > 0)
    RoomCategory category;      ///< Категория номера
    double pricePerNight;       ///< Цена за сутки (должна быть >= 0)
    bool isOccupied;            ///< Занят ли номер
    string guestName;      ///< Имя гостя (пустое, если номер свободен)

    /// Статический счётчик существующих объектов
    static int objectCount;

    /**
     * @brief Проверка инвариантов состояния объекта
     * @return true, если состояние корректно, иначе false
     */
    bool isStateValid() const;

public:
    /**
     * @brief Конструктор по умолчанию
     *
     * Создаёт номер №1 категории Economy с ценой 1000.0, свободный
     */
    HotelRoom();

    /**
     * @brief Параметризованный конструктор (свободный номер)
     * @param number Номер комнаты. Если <= 0, приводится к 1
     * @param category Категория номера
     * @param pricePerNight Цена за сутки. Если < 0, приводится к 0
     */

    HotelRoom(int number, RoomCategory category, double pricePerNight);

    /**
     * @brief Параметризованный конструктор (занятый номер)
     * @param number Номер комнаты. Если <= 0, приводится к 1
     * @param category Категория номера
     * @param pricePerNight Цена за сутки. Если < 0, приводится к 0
     * @param guestName Имя гостя. Если не пустое, номер помечается занятым
     */
    HotelRoom(int number, RoomCategory category, double pricePernight, const string& guestName);

    /// Деструктор. Уменьшает счётчик объектов
    ~HotelRoom();

    /// @brief Получить номер комнаты
    int getNumber() const;

    /// @brief Получить категорию номера
    RoomCategory getCategory() const;

    /// @brief Получить цену за сутки
    double getPricePerNight() const;

    /// @brief Узнать, занят ли номер
    bool isOccupiedStatus() const;

    /// @brief Получить имя гостя (пусто, если номер свободен)
    string getGuestName() const;

    /**
     * @brief Получить текущее количество существующих объектов
     * @return Число живых экземпляров HotelRoom
     */
    static int getObjectCount();

    /**
     * @brief Преобразовать категорию в строку
     * @param cat Категория номера
     * @return Строковое представление категории ("Эконом", "Стандарт", ...)
     */
    static string categoryToString(RoomCategory cat);

    /**
     * @brief Заселить гостя в номер
     * @param name Имя гостя (не должно быть пустым)
     * @return true при успехе, false если имя пустое или номер уже занят
     */
    bool checkIn(const string& name);

    /**
     * @brief Выселить гостя из номера
     * @return true при успехе, false если номер и так свободен
     */
    bool checkOut();

    /**
     * @brief Изменить цену за сутки
     * @param newPrice Новая цена (должна быть >= 0)
     * @return true при успехе, false если цена отрицательная
     */
    bool changePrice(double newPrice);

    /**
     * @brief Изменить категорию номера
     * @param newCategory Новая категория
     * @return true (операция всегда успешна)
     */
    bool changeCategory(RoomCategory newCategory);

    /// @brief Вывести состояние номера
    void print() const;
};

#endif