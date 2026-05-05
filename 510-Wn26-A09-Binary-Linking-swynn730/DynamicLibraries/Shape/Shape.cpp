#include "Shape.h"

#include <iostream>

Shape::Shape() = default;
Shape::~Shape() = default;

Shape::Shape(const Color color)
    : m_color(color)
{
}

Color Shape::getColor() const
{
    return m_color;
}

std::ostream& operator<<(std::ostream &out, const Shape& shape)
{
    out << "Shape: " << shape.getColor();
    return out;
}

std::ostream& operator<<(std::ostream& out, const Color color)
{
    if (color == Color::Red)
    {
        out << "Red";
    }
    else if (color == Color::Blue)
    {
        out << "Blue";
    }
    else
    {
        out << "Transparent";
    }

    return out;
}