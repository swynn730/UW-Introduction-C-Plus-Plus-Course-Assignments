#include "A5Q2_CharQueue2.h"


CharQueue2::CharQueue2()                                    // default constructor
    : CharQueue2(1)
{
}

CharQueue2::CharQueue2(size_t size)
{
}

size_t CharQueue2::capacity() const
{
    return queue.max_size();
}

void CharQueue2::enqueue(char ch) 
{
    queue.push_back(ch);
}

char CharQueue2::dequeue() 
{
    queue.pop_front();
    return queue.front();
}

bool CharQueue2::isEmpty() const 
{
    return queue.empty();
}