#ifndef ICARGOCARRIER_H
#define ICARGOCARRIER_H

/**
 * @interface ICargoCarrier
 * @brief Интерфейс для классов, способных перевозить грузы.
 */
class ICargoCarrier {
public:
    virtual ~ICargoCarrier() = default;

    /**
     * @brief Получить грузоподъёмность
     * @return Грузоподъёмность в тоннах
     */
    virtual double getCargoCapacity() const = 0;
};

#endif