#include "code.hpp"
#include <string>

int char_to_int(char c) {
    return c - '0';
}

int largest_number_in_string(const std::string& input) {
    int n = input.length();
    int a = char_to_int(input[0]);
    int b = char_to_int(input[1]);

    int i = 2;
    while(i < n) {
        auto curr = input[i] - '0';
        if(a < b) {
            a = b;
            b = curr;
        }
        if(b < curr) {
            b = curr;
        }
        i++;
    }
    return a*10 + b;
}
