#ifndef HOTELROOM_H
#define HOTELROOM_H

#include <string>

// Категория номера. Пользовательский тип.
enum class RoomCategory {
    Economy,
    Standard,
    Lux,
    President
};

class HotelRoom {
private:
    int number; // номер комнаты
    RoomCategory category; // категория
    double pricePerNight; // цена за сутки
    bool isOccupied; // занят ли номер
    std::string guestName; // имя гостя

    // Статический обработчик существующих объектов
    static int objectCount;

    // Вспомогательный метод проверки инвариантов
    bool isStateValid() const;

public:
    // Конструктор по умолчанию. Корректное начальное состояние
    HotelRoom();

    // Параметризованный конструктор. Имеет список инициализации
    HotelRoom(int number, RoomCategory category, double pricePerNight);

    // Параметризованный конструктор. Имеет список инициализации, а также гостя (т.е. занятый номер)
    HotelRoom(int number, RoomCategory category, double pricePernight, const std::string& guestName);

    // Деструктор
    ~HotelRoom();

    // Методы чтения (const)
    int getNumber() const;
    RoomCategory getCategory() const;
    double getPricePerNight() const;
    bool isOccupiedStatus() const;
    std::string getGuestName() const;

    // Статический метод кол-ва объектов
    static int getObjectCount();

    // Преобразование категории в строку (вспомогательное)
    static std::string categoryToString(RoomCategory cat);
};

#endif