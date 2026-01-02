#include <string>
#include <iostream>


bool is_palindrome(const std::string& str) {
    return std::equal(str.cbegin(), str.cend(),
str.crbegin());
}

int main() {
    std::cout <<is_palindrome("anavolimilovana");
}