#include <iostream>

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

int main() {
    point p1(2,3);
    point p2 = point(100, 200);
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;

    point* p3 = nullptr;

    p3 = new point(200, 300);
    std::cout << *p3 << std::endl;

    delete p3;

    point arr1[] = {{1,2}, {3,4}, {5,6}};

    std::cout << arr1[0] << std::endl;

    size_t number_of_points = 3;
    point* arr2 = new point[number_of_points];

    std::cout << "\nNiz objekata na hip memoriji: " << std::endl;
    for(size_t i = 0; i < number_of_points; i++) {
        std::cout << arr2[i] << std::endl;
    }

    delete[] arr2;

    return 0;
}