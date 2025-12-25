#include <iostream>
#include <sstream>
#include <memory>

#include "./common.hpp"

using namespace common;

void print_student(const std::shared_ptr<student>& s) {
    std::cout << s->m_name << " " << s->m_surname << std::endl;
    std::cout << "Use count: " << s.use_count() << std::endl;
}

int main() {
    std::shared_ptr<student> s = nullptr;
    s = std::make_shared<student>("John", "Doe");
    std::cout << s->m_name << " " << s->m_surname << std::endl;
    std::cout << "Use count: " << s.use_count() << std::endl;

    std::shared_ptr<student> s2 = s;
    std::cout << s2->m_name << " " << s2->m_surname << std::endl;
    std::cout << "Use count: " << s2.use_count() << std::endl;

    std::shared_ptr<student> s3 = s2;
    std::cout << s3->m_name << " " << s3->m_surname << std::endl;
    std::cout << "Use count: " << s3.use_count() << std::endl;

    // we can do this but we should not!    
    // because the shared_ptr will not be able to delete the object
    // and the object will leak
    //delete s.get();

    print_student(s);
    print_student(s2);
    print_student(s3);

    return 0;
}

