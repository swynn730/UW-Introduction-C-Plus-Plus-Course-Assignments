#include "Point.h"
#include <iomanip>


Point::Point(float x, float y)
{
    components[0] = x;
    components[1] = y;
}

void Point::stream(std::ostream& os) const 
{
    os << std::fixed << std::setprecision(1) << "POINT(" << get_x() << "f" << ", " << get_y() << "f" << ")";
}

float Point::get_x() const 
{
    return components[0];
}

float Point::get_y() const
{
    return components[1];
}

std::array<float, 2> Point::get_components() const
{
    return components;
}

void Point::set_x(float x) 
{
    components[0] = x;
}

void Point::set_y(float y) 
{
    components[1] = y;
}

void Point::set_components(float x, float y)
{
    components[0] = x;
    components[1] = y;
}