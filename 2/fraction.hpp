#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

class fraction {
public: 
    fraction(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator) {}
    ~fraction() {}
    int m_numerator;
    int m_denominator;

    fraction operator+(const fraction& other) const;
    fraction operator-(const fraction& other) const;
    fraction operator*(const fraction& other) const;
    fraction operator/(const fraction& other) const;
    bool operator==(const fraction& other) const;
    operator bool() const;

    friend std::ostream& operator<<(std::ostream& os, const fraction& f);
    friend std::istream& operator>>(std::istream& is, fraction& f);
};

#endif