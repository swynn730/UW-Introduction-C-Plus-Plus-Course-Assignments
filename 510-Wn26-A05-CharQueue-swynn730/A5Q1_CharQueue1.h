#pragma once
#include <memory>


class CharQueue1
{
public:
    CharQueue1();                                   // default constructor
    explicit CharQueue1(size_t size);
    CharQueue1(const CharQueue1& src);              // copy constructor
    CharQueue1(CharQueue1&& src);                   // move constructor
    CharQueue1& operator=(const CharQueue1& src);   // copy assignment operator
    CharQueue1& operator=(CharQueue1&& src);        // move assignment operator
    ~CharQueue1() = default;

    size_t capacity() const;

    void enqueue(char ch);
    char dequeue();
    bool isEmpty() const;

private:
    size_t queueSize = 1;
    size_t enqueueCounter = 0;
    size_t dequeueCounter = 0;
    std::unique_ptr<char[]> queue;
    auto resizeQueue(std::unique_ptr<char[]> &oldQueue, size_t oldQueueSize, size_t newQueueSize);
    void resetCounters();
};