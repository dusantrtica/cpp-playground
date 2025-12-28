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

unsigned long long largest_number_in_string_pt2(const std::string& input) {
    const int len = input.length();
    const int num_digits = 12;
    std::string number = "";

    int index_of_last_added_digit = 0;
    for(int i = 0; i < num_digits; i++) {        
        for(int j = index_of_last_added_digit; j <= len-(num_digits-i); j++) {
            if(input[j] > input[index_of_last_added_digit]) {
                index_of_last_added_digit = j;
            }
        }
        number += input[index_of_last_added_digit];
        index_of_last_added_digit++;
    }
    std::cout<<"found number " << number;
    try {
        return std::stoull(number);
    } catch(...) {
        return 0ul;
    }
}