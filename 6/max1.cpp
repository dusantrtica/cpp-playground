#include <iostream>

#define MAX(X, Y) (X > Y ? X : Y)

template <typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

template <typename ForwardIterator, typename Value>
void iota(ForwardIterator first, ForwardIterator last, Value value) {
    while (first != last) {
        *first = value;
        first++;
        value++;
    }
}

Fo

int main() {
    std::cout << MAX(2, 3) << std::endl;
    std::cout << max(3,5) << std::endl;
    return 0;
}