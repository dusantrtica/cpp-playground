#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

class my_file {
public:
    my_file(const std::string& filename) {       
        std::cout << "Opening file: " << filename << std::endl;
        m_file = fopen(filename.c_str(), "r");
        if(!m_file) {
            throw std::runtime_error("Failed to open file: " + filename);
        }
    }

    ~my_file() {
        if(m_file) {
            fclose(m_file);
            m_file = nullptr;
            std::cout << "File closed" << std::endl;
        }
    }
private:
    FILE* m_file = nullptr;
};

int main() {
    my_file file("~/projects/cpp-playground/2/data.txt");
    return 0;
}