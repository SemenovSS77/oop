#include "Fraction.h"
#include <numeric>

using namespace std;

int Fraction::totalOperations = 0;
int Fraction::destroyedCount = 0;

void Fraction::normalize() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    int g = gcd(abs(numerator), denominator);
    if (g > 1) {
        numerator /= g;
        denominator /= g;
    }
}

Fraction::Fraction() :
    numerator(0),
    denominator(1),
    historyCapacity(2),
    historySize(0)
{
    history = new string[historyCapacity];
    addHistoryEntry("Создана дробь по умолчанию: 0/1");
}

Fraction::Fraction(int num, int den) :
    numerator(num),
    denominator(den),
    historyCapacity(2),
    historySize(0)
{
    history = new string[historyCapacity];
    if (den == 0) {
        cerr << "Ошибка. Знаменатель не может быть 0. Устанавливаем 1" << endl;
        denominator = 1;
    }
    normalize();
    addHistoryEntry("Создана дробь: " + to_string(numerator) + "/" + to_string(denominator));
}

Fraction::Fraction(int value) :
    numerator(value),
    denominator(1),
    historyCapacity(2),
    historySize(0)
{
    history = new string[historyCapacity];
    addHistoryEntry("Создана дробь из целого: " + to_string(value));
}

Fraction::~Fraction() {
    delete[] history;
    destroyedCount++;
}

int Fraction::getNumerator() const {return numerator;}
int Fraction::getDenominator() const {return denominator;}
int Fraction::getTotalOperations() {return totalOperations;}
void Fraction::resetTotalOperations() {totalOperations = 0;}
int Fraction::getDestroyedCount() {return destroyedCount;}

void Fraction::print() const {
    cout << numerator << "/" << denominator;
}

void Fraction::printHistory() const {
    cout << "История объекта " << numerator << "/" << denominator << ":" << endl;
    for (int i = 0; i < historySize; i++) {
        cout << " " << (i + 1) << ". " << history[i] << endl;
    }
}

void Fraction::addHistoryEntry(const string& entry) const {
    if (historySize >= historyCapacity) {
        historyCapacity *= 2;
        string* newHistory = new string[historyCapacity];
        for (int i = 0; i < historySize; i++) {
            newHistory[i] = history[i];
        }
        delete[] history;
        history = newHistory;
    }
    history[historySize] = entry;
    historySize++;
}

// Унарные операторы
Fraction& Fraction::operator++() {
    totalOperations++;
    numerator += denominator;
    normalize();
    addHistoryEntry("++: стало " + to_string(numerator) + "/" + to_string(denominator));
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    ++(*this);
    return temp;
}

Fraction& Fraction::operator--() {
    totalOperations++;
    numerator -= denominator;
    normalize();
    addHistoryEntry("--: стало " + to_string(numerator) + "/" + to_string(denominator));
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction temp = *this;
    --(*this);
    return temp;
}

// Арифметическое присваивание
Fraction& Fraction::operator+=(const Fraction& other) {
    totalOperations++;
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
    normalize();
    addHistoryEntry("+= " + to_string(other.numerator) + "/" + to_string(other.denominator));
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& other) {
    totalOperations++;
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator *= other.denominator;
    normalize();
    addHistoryEntry("-= " + to_string(other.numerator) + "/" + to_string(other.denominator));
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other) {
    totalOperations++;
    numerator *= other.numerator;
    denominator *= other.denominator;
    normalize();
    addHistoryEntry("*= " + to_string(other.numerator) + "/" + to_string(other.denominator));
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& other) {
    totalOperations++;
    if (other.numerator == 0) {
        cerr << "Ошибка. Деление на ноль-дробь" << endl;
        return *this;
    }
    numerator *= other.denominator;
    denominator *= other.numerator;
    normalize();
    addHistoryEntry("/= " + to_string(other.numerator) + "/" + to_string(other.denominator));
    return *this;
}

// Бинарные через присваивание
Fraction operator+(Fraction lhs, const Fraction& rhs) {
    lhs += rhs;
    return lhs;
}

Fraction operator-(Fraction lhs, const Fraction& rhs) {
    lhs -= rhs;
    return lhs;
}

Fraction operator*(Fraction lhs, const Fraction& rhs) {
    lhs *= rhs;
    return lhs;
}

Fraction operator/(Fraction lhs, const Fraction& rhs) {
    lhs /= rhs;
    return lhs;
}

// Сравнения
bool operator<(const Fraction& a, const Fraction& b) {
    return a.numerator * b.denominator < b.numerator * a.denominator;
}

bool operator>(const Fraction& a, const Fraction& b) {
    return b < a;
}

bool operator<=(const Fraction& a, const Fraction& b) {
    return !(b < a);
}

bool operator>=(const Fraction& a, const Fraction& b) {
    return !(a < b);
}

bool operator==(const Fraction& a, const Fraction& b) {
    return a.numerator == b.numerator && a.denominator == b.denominator;
}

bool operator!=(const Fraction& a, const Fraction& b) {
    return !(a == b);
}