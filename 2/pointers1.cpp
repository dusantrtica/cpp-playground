#include <iostream>
#include "./common.hpp"

using namespace common;

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