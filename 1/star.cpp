#include <iostream>

void draws_stars_around_text(const std::vector<std::string>& messages, size_t maximum_length);
void input_messages(std::vector<std::string>& messages, size_t& maximum_length);
int main() {
    std::vector<std::string> messages;
    size_t maximum_length = 0;
    input_messages(messages, maximum_length);

    draws_stars_around_text(messages, maximum_length);

    return 0;
}

void draws_stars_around_text(const std::vector<std::string>& messages, size_t maximum_length) {
    const std::string stars_line(maximum_length+4, '*');
    // Upper border
    std::cout << stars_line << std::endl;

    // Messages
    for(const auto& message : messages) {
        std::cout << "* "
        << message
        << std::string(maximum_length - message.size(), ' ') 
        << " *" << std::endl;
    }

    // Lower border
    std::cout << stars_line << std::endl;   
}

void input_messages(std::vector<std::string>& messages, size_t& maximum_length) {
    std::string line;
    while(getline(std::cin, line)) {
        messages.push_back(line);
        maximum_length = std::max(maximum_length, line.size());
    }
}