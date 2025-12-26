#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <memory>

class list {
public:
    list() = default;
    list(const list& other);
    list(list&& other);
    // list b = [1,2,3]
    // list a = b
    list& operator=(const list& other);
    // list a = [1,2,3]
    list& operator=(list&& other);
    ~list();

    void push_front(const int value);
    void push_back(const int value);
    void pop_front();
    size_t size() const;

    int operator[](const size_t index) const;
    int& operator[](const size_t index);

private:
    struct element {
        int value;
        std::unique_ptr<element> next;
        element(int value, std::unique_ptr<element>&& next = nullptr): value(value), next(std::move(next)) {}
    };

    std::unique_ptr<element>m_head = nullptr;
    size_t m_size = 0;

    element* at(const size_t index) const;
};

#endif