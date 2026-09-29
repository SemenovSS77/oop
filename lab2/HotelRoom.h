#ifndef HOTELROOM_H
#define HOTELROOM_H

#include <string>

enum class RoomCategory {
    Economy,
    Standard,
    Lux,
    President
};

class HotelRoom {
private:
    int number;
    RoomCategory category;
    double pricePerNight;
    bool isOccupied;
    std::string guestName;

    static int objectCount;

    bool isStateValid() const;

public:
    HotelRoom();

    HotelRoom(int number, RoomCategory category, double pricePerNight);
    
    HotelRoom(int number, RoomCategory category, double pricePernight, const std::string& guestName);
};

#endif