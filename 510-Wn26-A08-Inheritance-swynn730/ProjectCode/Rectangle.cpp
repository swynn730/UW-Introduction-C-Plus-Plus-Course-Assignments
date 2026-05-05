#include "Rectangle.h"


Rectangle::Rectangle(Point upper_left, Point lower_right, std::ostream& os) : Shape(os)
{
    dimensions[0] = upper_left;
    dimensions[1] = lower_right;
}

void Rectangle::draw() const 
{
    stream(canvas);
}

void Rectangle::stream(std::ostream& os) const 
{
    os << "RECTANGLE[" << dimensions[0] << ", " << dimensions[1] << "]";
}

Point Rectangle::get_upper_left() const
{
    return dimensions[0];
}

Point Rectangle::get_lower_right() const
{
    return dimensions[1];
}

std::array<Point, 2> Rectangle::get_dimensions() const
{
    return dimensions;
}

void Rectangle::set_upper_left(Point upper_left)
{
    dimensions[0] = upper_left;
}

void Rectangle::set_lower_right(Point lower_right)
{
    dimensions[1] = lower_right;
}

void Rectangle::set_dimensions(Point upper_left, Point lower_right)
{
    dimensions[0] = upper_left;
    dimensions[1] = lower_right;
}

Rectangle& Rectangle::operator+=(const Point& point) 
{
    dimensions[0] = Point{dimensions[0].get_x() + point.get_x(), dimensions[0].get_y() + point.get_y()};
    dimensions[1] = Point{dimensions[1].get_x() + point.get_x(), dimensions[1].get_y() + point.get_y()};
    return *this;
}

Rectangle Rectangle::operator+(const Point& point) const 
{
    Rectangle temp = Rectangle{get_upper_left(), get_lower_right(), canvas};
    temp += point;
    return temp;
}

Rectangle& Rectangle::operator-=(const Point& point)
{
    dimensions[0] = Point{dimensions[0].get_x() - point.get_x(), dimensions[0].get_y() - point.get_y()};
    dimensions[1] = Point{dimensions[1].get_x() - point.get_x(), dimensions[1].get_y() - point.get_y()};
    return *this;
}

Rectangle Rectangle::operator-(const Point& point) const
{
    Rectangle temp = Rectangle(get_upper_left(), get_lower_right(), canvas);
    temp -= point;
    return temp;
}

Rectangle Rectangle::operator-() const
{
    Rectangle temp = Rectangle(get_upper_left(), get_lower_right(), canvas);
    float ux = -temp.get_upper_left().get_x();
    float uy = -temp.get_upper_left().get_y();
    float lx = -temp.get_lower_right().get_x();
    float ly = -temp.get_lower_right().get_y();
    
    temp.dimensions[0].set_x(ux);
    temp.dimensions[0].set_y(uy);
    temp.dimensions[1].set_x(lx);
    temp.dimensions[1].set_y(ly);
    return temp;
}

bool Rectangle::operator==(const Rectangle& otherRectangle) const
{
    bool ux = get_upper_left().get_x() == otherRectangle.get_upper_left().get_x();
    bool uy = get_upper_left().get_y() == otherRectangle.get_upper_left().get_y();
    bool lx = get_lower_right().get_x() == otherRectangle.get_lower_right().get_x();
    bool ly = get_lower_right().get_y() == otherRectangle.get_lower_right().get_y();
    return ux && uy && lx && ly;
}

bool Rectangle::operator!=(const Rectangle& otherRectangle) const
{
    return !(*this == otherRectangle);
}