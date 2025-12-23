#include <iostream>
#include <vector>
#include <numeric>

int main () {
    std::vector<int> numbers;

    int number;
    while (std::cin >> number) {
        numbers.push_back(number);
    }

    double average = std::accumulate(numbers.begin(), numbers.end(), 0) / numbers.size();
    std::cout << "Average: " << average << std::endl;

    return 0;
}
