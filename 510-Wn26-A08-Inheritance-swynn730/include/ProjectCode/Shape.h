#pragma once

#include <ostream>
#include <iomanip>


class Shape
{
protected:
    std::ostream& canvas;

public:
    Shape() = delete;
    explicit Shape(std::ostream& os) : canvas(os) {};
    Shape(const Shape& src) = default;              // copy constructor
    Shape(Shape&& src) = default;                   // move constructor
    Shape& operator=(const Shape& src) = delete;   // copy assignment operator
    Shape& operator=(Shape&& src) = delete;        // move assignment operator
    virtual ~Shape() = default;

    virtual void draw() const = 0;
    virtual void stream(std::ostream& os) const = 0;
};

// Use the virtual stream operator of the shape. This way a single override of operator<<() for shape
// correctly streams all subclasses
inline std::ostream& operator<<(std::ostream& os, const Shape& shape)
{
    shape.stream(os);
    os << std::fixed << std::setprecision(1);
    return os;
}