#include "A4Q2_Write.h"
#include <iomanip>


void write (std::ostream& os, int value) 
{
    os << value;
}

void write (std::ostream& os, float value) 
{
    os << std::fixed << std::setprecision(1) << value;
}

void write (std::ostream& os, std::string value) 
{
    os << value;
}