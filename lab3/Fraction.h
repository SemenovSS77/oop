#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @class Fraction
 * @brief Класс, представляющий рациональное число (дробь) вида numerator/denominator
 *
 * Хранит числитель и знаменатель, автоматически нормализует дробь
 * (сокращает и переносит знак в числитель). Поддерживает арифметические
 * операции, сравнения, инкремент/декремент. Ведёт историю операций
 * и общий счётчик операций
 *
 * @note Дробь всегда хранится в несократимом виде, знаменатель всегда > 0
 *
 * @warning Все арифметические операции выполняются над целыми числами.
 *          При переполнении `int` результат может быть некорректным.
 */
class Fraction {
private:
    int numerator;                        ///< Числитель
    int denominator;                      ///< Знаменатель
    mutable vector<string> history;       ///< История операций
    static int totalOperations;           ///< Общий счётчик выполненных операций
    static int destroyedCount;            ///< Общий счётчик уничтоженных объектов

    /**
     * @brief Приведение дроби к несократимому виду и нормализация знака.
     *
     * Если знаменатель отрицательный - знак переносится в числитель.
     * Затем дробь сокращается.
     */
    void normalize();

public:
    // ----- Конструкторы -----

    /**
     * @brief Конструктор по умолчанию (создаёт дробь 0/1)
     */
    Fraction();

    /**
     * @brief Параметризованный конструктор.
     * @param num Числитель.
     * @param den Знаменатель (если равен 0 - заменяется на 1)
     *
     * Дробь автоматически нормализуется (сокращается).
     */
    Fraction(int num, int den);

    /**
     * @brief Явный конструктор из целого числа.
     * @param value Целое число, становится числителем (знаменатель = 1).
     *
     * @note Помечен `explicit` - запрещает неявное преобразование int -> Fraction.
     */
    explicit Fraction(int value);

    // ----- Деструктор -----

    /**
     * @brief Деструктор (увеличивает счётчик уничтоженных объектов)
     */
    ~Fraction();

    // ----- Геттеры -----

    /// @brief Получить числитель.
    int getNumerator() const;

    /// @brief Получить знаменатель.
    int getDenominator() const;

    /// @brief Получить общее количество выполненных операций.
    static int getTotalOperations();

    /// @brief Сбросить счётчик операций в 0.
    static void resetTotalOperations();

    /// @brief Получить количество уничтоженных объектов.
    static int getDestroyedCount();

    // ----- Вывод -----

    /// @brief Вывести дробь в формате "numerator/denominator".
    void print() const;

    /// @brief Вывести историю операций объекта.
    void printHistory() const;

    /**
     * @brief Добавить запись в историю операций.
     * @param entry Текст записи.
     *
     * @note Метод объявлен `const`, но меняет `mutable`-поле `history`.
     */
    void addHistoryEntry(const string& entry) const;

    // ----- Унарные операторы -----

    /**
     * @brief Префиксный инкремент. Увеличивает дробь на 1.
     * @return Ссылка на изменённый объект.
     */
    Fraction& operator++();

    /**
     * @brief Постфиксный инкремент. Возвращает копию ДО изменения.
     * @param int Фиктивный параметр (отличает постфиксную форму).
     * @return Копия объекта до увеличения.
     */
    Fraction operator++(int);

    /**
     * @brief Префиксный декремент. Уменьшает дробь на 1.
     * @return Ссылка на изменённый объект.
     */
    Fraction& operator--();

    /**
     * @brief Постфиксный декремент. Возвращает копию ДО изменения.
     * @param int Фиктивный параметр.
     * @return Копия объекта до уменьшения.
     */
    Fraction operator--(int);

    // ----- Арифметическое присваивание -----

    /**
     * @brief Сложение с присваиванием.
     * @param other Правая дробь.
     * @return Ссылка на изменённый объект.
     */
    Fraction& operator+=(const Fraction& other);

    /**
     * @brief Вычитание с присваиванием.
     * @param other Правая дробь.
     * @return Ссылка на изменённый объект.
     */
    Fraction& operator-=(const Fraction& other);

    /**
     * @brief Умножение с присваиванием.
     * @param other Правая дробь.
     * @return Ссылка на изменённый объект.
     */
    Fraction& operator*=(const Fraction& other);

    /**
     * @brief Деление с присваиванием.
     * @param other Правая дробь. Не должна быть нулём.
     * @return Ссылка на изменённый объект.
     *
     * @warning При делении на нулевую дробь выводится ошибка, объект не меняется.
     */
    Fraction& operator/=(const Fraction& other);

    // ----- Бинарные арифметические -----

    /**
     * @brief Сложение дробей
     * @param lhs Левая дробь (передаётся по значению - копия)
     * @param rhs Правая дробь
     * @return Новая дробь - сумма
     */
    friend Fraction operator+(Fraction lhs, const Fraction& rhs);

    /**
     * @brief Вычитание дробей
     * @param lhs Левая дробь
     * @param rhs Правая дробь
     * @return Новая дробь - разность
     */
    friend Fraction operator-(Fraction lhs, const Fraction& rhs);

    /**
     * @brief Умножение дробей
     * @param lhs Левая дробь
     * @param rhs Правая дробь
     * @return Новая дробь - произведение
     */
    friend Fraction operator*(Fraction lhs, const Fraction& rhs);

    /**
     * @brief Деление дробей
     * @param lhs Левая дробь
     * @param rhs Правая дробь (не должна быть нулём)
     * @return Новая дробь - частное
     */
    friend Fraction operator/(Fraction lhs, const Fraction& rhs);

    // ----- Сравнения -----

    /// @brief Оператор "меньше"
    friend bool operator<(const Fraction& a, const Fraction& b);

    /// @brief Оператор "больше"
    friend bool operator>(const Fraction& a, const Fraction& b);

    /// @brief Оператор "меньше или равно".
    friend bool operator<=(const Fraction& a, const Fraction& b);

    /// @brief Оператор "больше или равно"
    friend bool operator>=(const Fraction& a, const Fraction& b);

    /// @brief Оператор равенства
    friend bool operator==(const Fraction& a, const Fraction& b);

    /// @brief Оператор неравенства
    friend bool operator!=(const Fraction& a, const Fraction& b);
};

#endif