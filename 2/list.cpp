#include "list.hpp"
#include <iostream>

list::list(const list& other) {
    // [1,2,3] => [1,2,3]
    auto e = other.m_head.get();
    while(e) {
        push_back(e->value);
        e = e->next.get();
    }
}

list::list(list&& other) : m_head(std::move(other.m_head)), m_size(other.m_size) {
    other.m_size = 0;
}

list& list::operator=(const list& other) {
    if (this == &other) {
        return *this;
    }

    // copy-swap idiom
    auto tmp(other);
    // swap the heads and the sizes
    std::swap(m_head, tmp.m_head);
    std::swap(m_size, tmp.m_size);
    
    return *this;
}

// list a = [1,2,3]
list& list::operator=(list&& other) {
    auto tmp(std::move(other));
    std::swap(m_head, tmp.m_head);
    std::swap(m_size, tmp.m_size);
    return *this;
}

list::~list() {
    // malo kasnije da se pozabavimo
    while(m_head) {
        pop_front();
    }
}

void list::push_front(const int value) {
    auto new_element = std::make_unique<element>(value, std::move(m_head));
    m_head = std::move(new_element);
    m_size++;
}

void list::push_back(const int value) {
    auto new_element = std::make_unique<element>(value, nullptr);
    if(!m_head) {
        m_head = std::move(new_element);
    } else {
        auto e = m_head.get();
        while(e->next) {
            e = e->next.get();
        }
        e->next = std::move(new_element);
    }

    m_size++;
}

void list::pop_front() {
    auto old_head = std::move(m_head);
    m_head = std::move(old_head->next);
    m_size--;
}

int list::operator[](const size_t index) const {
    return  at(index)->value;
}

int& list::operator[](const size_t index) {
    return at(index)->value;
}

list::element* list::at(const size_t index) const {
    if(!m_head) {
        return nullptr;
    }

    auto e = m_head.get();

    for(auto i = 0u; i < index; i++) {
        e = e->next.get();
        if(!e) {
            return nullptr;
        }
    }
    return e;
}

int main() {
    list l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1[2] = 10;
    std::cout << l1[0] << std::endl;
    std::cout << l1[1] << std::endl;
    std::cout << l1[2] << std::endl;
    return 0;
}