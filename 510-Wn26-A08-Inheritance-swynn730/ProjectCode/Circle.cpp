#include "Circle.h"


Circle::Circle(Point p1, float value, std::ostream& os) : Shape(os)
{
    origin = p1;
    radius = value;
}

void Circle::draw() const 
{
    stream(canvas);
}

void Circle::stream(std::ostream& os) const
{
    os << "CIRCLE[" << origin << ", " << radius << "f" << "]";
}

Point Circle::get_origin() const
{
    return origin;
}

float Circle::get_radius() const 
{
    return radius;
}

void Circle::set_origin(Point p1) 
{
    origin = p1;
}

void Circle::set_radius(float r)
{
    radius = r;
}

Circle& Circle::operator+=(const Point& point) 
{
    origin = Point{origin.get_x() + point.get_x(), origin.get_y() + point.get_y()};
    return *this;
}

Circle Circle::operator+(const Point& point) const 
{
    Circle temp = Circle{origin, radius, canvas};
    temp += point;
    return temp;
}

Circle& Circle::operator-=(const Point& point)
{
    origin = Point{origin.get_x() - point.get_x(), origin.get_y() - point.get_y()};
    return *this;
}

Circle Circle::operator-(const Point& point) const
{
    Circle temp = Circle(origin, radius, canvas);
    temp -= point;
    return temp;
}

Circle Circle::operator-() const
{
    Circle temp = Circle(origin, radius, canvas);
    float ox = -temp.origin.get_x();
    float oy = -temp.origin.get_y();    
    temp.set_origin(Point{ox, oy});
    return temp;
}

bool Circle::operator==(const Circle& otherCircle) const
{
    bool ox = origin.get_x() == otherCircle.origin.get_x();
    bool oy = origin.get_y() == otherCircle.origin.get_y();
    bool rad = radius == otherCircle.radius;
    return ox && oy && rad;
}

bool Circle::operator!=(const Circle& otherCircle) const
{
    return !(*this == otherCircle);
}

Circle Circle::operator*(double value) const 
{
    Circle temp = Circle{origin, radius, canvas};
    temp.radius = temp.radius * value;
    return temp;
}