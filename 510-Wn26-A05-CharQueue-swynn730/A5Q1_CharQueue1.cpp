#include "A5Q1_CharQueue1.h"


auto CharQueue1::resizeQueue(std::unique_ptr<char[]> &oldQueue, size_t oldQueueSize, size_t newQueueSize)
{
    auto newQueue = std::make_unique<char[]>(newQueueSize);
    std::memcpy(newQueue.get(), oldQueue.get(), oldQueueSize * sizeof(char));
    return newQueue;
}

void CharQueue1::resetCounters()
{
    enqueueCounter = 0;
    dequeueCounter = 0;
}

CharQueue1::CharQueue1()                                    // default constructor
    : CharQueue1(1)
{
}

CharQueue1::CharQueue1(size_t size) 
    : queueSize{size}, enqueueCounter{0}, dequeueCounter{0}, queue{std::make_unique<char[]>(queueSize)}
{
}

CharQueue1::CharQueue1(const CharQueue1& src)               // copy constructor
    : queueSize{src.queueSize}, enqueueCounter{src.enqueueCounter}, dequeueCounter{src.dequeueCounter}, queue{std::make_unique<char[]>(queueSize)}
{
    std::memcpy(queue.get(), src.queue.get(), queueSize * sizeof(char));
}

CharQueue1::CharQueue1(CharQueue1&& src)                    // move constructor
    : queueSize{src.queueSize}, enqueueCounter{src.enqueueCounter}, dequeueCounter{src.dequeueCounter}, queue{std::move(src.queue)}
{
    src.queueSize = 0;
    src.enqueueCounter = 0;
    src.dequeueCounter = 0;
}

CharQueue1& CharQueue1::operator=(const CharQueue1& src)    // copy assignment operator
{
    if (this == &src)
    {
        return *this;
    }
    queueSize = src.queueSize;
    enqueueCounter = src.enqueueCounter;
    dequeueCounter = src.dequeueCounter;
    queue = std::make_unique<char[]>(queueSize);
    std::memcpy(queue.get(), src.queue.get(), queueSize * sizeof(char));
    return *this;
}

CharQueue1& CharQueue1::operator=(CharQueue1&& src)         // move assignment operator
{
    if (this == &src)
    {
        return *this;
    }
    queueSize = src.queueSize;
    enqueueCounter = src.enqueueCounter;
    dequeueCounter = src.dequeueCounter;
    queue = std::move(src.queue);   // src becomes nullptr

    src.queueSize = 0;
    src.enqueueCounter = 0;
    src.dequeueCounter = 0;
    return *this;
}

size_t CharQueue1::capacity() const
{
    return queueSize;
}

void CharQueue1::enqueue(char ch) 
{
    if (enqueueCounter >= queueSize - 1) 
    {
        size_t newQueueSize = queueSize + 1;
        queue = resizeQueue(queue, queueSize, newQueueSize);
        queueSize = newQueueSize;
    }
    queue[enqueueCounter] = ch;
    enqueueCounter += 1;
}

char CharQueue1::dequeue() 
{
    char ch = queue[dequeueCounter];
    if (dequeueCounter < enqueueCounter)
    {
        dequeueCounter += 1;
        if (dequeueCounter == enqueueCounter)
        {
            resetCounters();
        }
    }
    return ch;
}

bool CharQueue1::isEmpty() const 
{
    return enqueueCounter == dequeueCounter;
}