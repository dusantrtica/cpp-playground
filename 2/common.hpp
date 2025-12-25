#include <iostream>
#include <sstream>

namespace common {

// razlike nema puno izmedju klase i strukture, samo sto 
// klasa je defaultno private, a struktura je defaultno public
struct point {
    point(double x = 0, double y = 0) : m_x(x), m_y(y) {}
    double m_x;
    double m_y;

    std::string to_string() const {
        return "(" + std::to_string(m_x) + ", " + std::to_string(m_y) + ")";
    }

    friend std::ostream& operator<<(std::ostream& os, const point& p) {
        os << p.to_string();
        return os;
    }
};
struct student {
    student(const std::string& name, const std::string& surname) : m_name(name), m_surname(surname) {
        std::stringstream ss;
        ss << "Student: " << m_name << " " << m_surname;
        std::cout << ss.str() << std::endl;
    }

    std::string m_name;
    std::string m_surname;

    ~student() {
        std::cout << "Destructor called for " << m_name << " " << m_surname << std::endl;
    }
};
};
