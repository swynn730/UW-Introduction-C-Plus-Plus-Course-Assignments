#include "Probe.h"


int Probe::reportCreationCount() const
{
    return creationCount;
}

int Probe::reportCurrentCount() const 
{
    return currentCount;
}

Probe& Probe::operator++()
{
    creationCount ++;
    currentCount ++;
    return *this;
}

Probe& Probe::operator--()
{
    if(currentCount > 0) 
    {
        currentCount --;
    }
    return *this;
}

void Probe::resetCounts() 
{
    creationCount = 0;
    currentCount = 0;
}

std::ostream& operator<<(std::ostream& os, const Probe& p)
{
    os 
    << "The creation count is: " << p.creationCount
    << ", " 
    << "The current count is: " << p.currentCount;
    return os;
}