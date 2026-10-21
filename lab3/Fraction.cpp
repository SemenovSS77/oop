#include "Fraction.h"
#include <numeric>
#include <cmath>
#include <stdexcept>

using namespace std;

int Fraction::objectCount = 0;

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
    denominator(1)
{
    objectCount++;
    history.push_back("Создана дробь по умолчанию: 0/1");
}

Fraction::Fraction(int num, int den) :
    numerator(num),
    denominator(den)
{
    if (den == 0) {
        cerr << "Ошибка. Знаменатель не может быть 0. Устанавливаем 1" << endl;
        denominator = 1;
    }
    normalize();
    objectCount++;
    history.push_back("Создана дробь: " + to_string(numerator) + "/" to_string(denominator));
}

Fraction::Fraction(int value) :
    numerator(value),
    denominator(1)
{
    objectCount++;
    history.push_back("Создана дробь из целого: " + to_string(value));
}

Fraction::~Fraction() {
    objectCount--;
    cout << "[Fraction] Уничтожена дробь " << numberator << "/" << denominator << " (осталось объектов: " << objectCount << ")" << endl;
}

void Fraction::printHistory() const {
    cout << "История объекта " << numerator << "/" << denominator << ":" << endl;
    for (size_t i = 0; i < history.size(); i++) {
        cout << " " << (i + 1) << ". " << history[i] << endl;
    }
}

void Fraction::addHistoryEntry(const string& entry) const {
    history.push_back(entry);
}