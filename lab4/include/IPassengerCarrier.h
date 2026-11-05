#ifndef IPASSENGERCARRIER_H
#define IPASSENGERCARRIER_H

/**
 * @interface IPassengerCarrier
 * @brief Интерфейс для классов, способных перевозить пассажиров.
 */
class IPassengerCarrier {
public:
    virtual ~IPassengerCarrier() = default;

    /**
     * @brief Получить пассажировместимость
     * @return Количество мест для пассажиров
     */
    virtual int getPassengerCapacity() const = 0;
};

#endif