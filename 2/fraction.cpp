#include "fraction.hpp"
#include <iostream>

fraction fraction::operator+(const fraction& other) const {
    return fraction(m_numerator * other.m_denominator + other.m_numerator * m_denominator, m_denominator * other.m_denominator);
}

fraction fraction::operator-(const fraction& other) const {
    return fraction(m_numerator * other.m_denominator - other.m_numerator * m_denominator, m_denominator * other.m_denominator);
}

fraction fraction::operator*(const fraction& other) const {
    return fraction(m_numerator * other.m_numerator, m_denominator * other.m_denominator);
}

fraction fraction::operator/(const fraction& other) const {
    return fraction(m_numerator * other.m_denominator, m_denominator * other.m_numerator);
}

bool fraction::operator==(const fraction& other) const {
    return m_numerator == other.m_numerator && m_denominator == other.m_denominator;
}
fraction::operator bool() const {
    return m_numerator != 0 && m_denominator != 0;
}
std::ostream& operator << (std::ostream& os, const fraction& f) {
    os << f.m_numerator << "/" << f.m_denominator;
    return os;
}

std::istream& operator >> (std::istream& is, fraction& f) {
    char slash;
    is >> f.m_numerator >> slash >> f.m_denominator;
    return is;
}
int main() {
    fraction f1(1, 2);
    fraction f2(3, 4);
    fraction f3 = f1 + f2;
    std::cout << f3 << std::endl;
    fraction f(0, 1);
    std::cin >> f;
    std::cout << f << std::endl;

    std::cout<<bool(fraction(0, 1)) << std::endl;
    return 0;
}