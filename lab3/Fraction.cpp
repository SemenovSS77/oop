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