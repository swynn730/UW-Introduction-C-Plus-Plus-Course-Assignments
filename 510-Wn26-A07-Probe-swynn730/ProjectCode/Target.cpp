#include "Target.h"


Target::Target() 
{
    ++p;
}

int Target::reportCreationCount() const
{
    return p.reportCreationCount();
}

int Target::reportCurrentCount() const
{
    return p.reportCurrentCount();
}

Target::~Target()
{
    --p;
}

void Target::resetCounts() 
{
    p.resetCounts();
}

std::ostream& operator<<(std::ostream& os, const Target&)
{
    os << Target::p;
    return os;
}