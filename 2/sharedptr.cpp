#include <iostream>
#include <sstream>
std::string* f() {
    return new std::string("Hello, World!");
}

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

int main() {
    student* s = new student("John", "Doe");
    
    return 0;
}

