#include "student.hpp"

int main() {
    student* s1 = new master_student("John", Studies::Mathematics, "Thesis", "Mentor");
    std::cout << s1->name() << std::endl;
    if(dynamic_cast<master_student*>(s1)) {
        std::cout << "s1 is a master student" << std::endl;
    } else {
        std::cout << "s1 is not a master student" << std::endl;
    }
    delete s1;
    return 0;
}
