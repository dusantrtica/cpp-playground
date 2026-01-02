#include <iostream>
#include <iterator>
#include <vector>

template <typename T>
auto even(T x) -> decltype(T::value_type) {
    return x % 2 == 0;
}

int main () {
    std::vector<int> xs;

    std::copy(
        std::istream_iterator<int>(std::cin),
        std::istream_iterator<int>(),
        std::back_inserter(xs)
    );

    std::copy(
        xs.cbegin(),
        xs.cend(),
        std::ostream_iterator<int>(std::cout)
    );
}