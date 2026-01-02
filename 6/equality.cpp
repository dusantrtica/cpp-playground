#include <string>
#include <iostream>


template <typename T>
class equality_testable {
public:
    bool operator== (const T& other) const {
        return !(static_cast<const T&>(*this) != other);
    }
    bool operator!= (const T& other) const {
        return !(static_cast<const T&>(*this) == other);
    }
protected:
    equality_testable(){};
};

class test : public equality_testable<test> {
public:
    test(std::string data): m_data(data) {}

    bool operator== (const test& other) const {
        return other.m_data == other.m_data;
    }
private:
    std::string m_data;
};

int main() {
    test x1("a");
    test x2("a");

    std::cout << (x1 != x2);
}