#pragma once
#include <deque>


class CharQueue2
{
public:
    CharQueue2();                                             // default constructor
    explicit CharQueue2(size_t size);
    CharQueue2(const CharQueue2& src) = default;              // copy constructor
    CharQueue2(CharQueue2&& src) = default;                   // move constructor
    CharQueue2& operator=(const CharQueue2& src) = default;   // copy assignment operator
    CharQueue2& operator=(CharQueue2&& src) = default;        // move assignment operator
    ~CharQueue2() = default;

    size_t capacity() const;

    void enqueue(char ch);
    char dequeue();
    bool isEmpty() const;

private:
    size_t enqueueCounter = 0;
    size_t dequeueCounter = 0;
    std::deque<char> queue = {1};
};