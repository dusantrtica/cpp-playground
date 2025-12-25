#include <iostream>
#include "./common.hpp"

using namespace common;

void print_student(const std::unique_ptr<student>& s) {
    std::cout << s->m_name << " " << s->m_surname << std::endl;
}


void print_with_move(const std::unique_ptr<student> s) {
    std::cout << s->m_name << " " << s->m_surname << std::endl;
}
int main() {
    std::unique_ptr<student> s = nullptr;
    s = std::make_unique<student>("John", "Doe");
    print_student(s);
    // std::cout << "Use count: " << s.use_count() << std::endl;
    print_with_move(std::move(s));

    print_student(s); // this will crash as s is now nullptr
    return 0;
}