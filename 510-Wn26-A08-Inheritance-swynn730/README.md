Inheritance and Operators
As always, write tests to exercise the functionality implemented by your classes and endeavor to cover all code paths.

Shape Inheritance
Given the following incomplete Shape base class:

#pragma once

#include <ostream>

class Shape
{
public:
    virtual void draw() const = 0;
    virtual void stream(std::ostream& os) const = 0;
};

inline std::ostream& operator<<(std::ostream& os, const Shape& shape)
{
    shape.stream(os);
    return os;
}
Complete the Shape class by implementing rule-of-5, and carefully consider how the destructor should be managed given that Shape will be used as a base class.

Define classes Circle and Rectangle, deriving from the base class Shape. Implement appropriate member data; for example, a rectangle has an upper left and lower right position, and a circle has an origin and radius. Create and use a class named Point to store X and Y positions.

Add an appropriate constructor to set the geometry for each class. Add appropriate accessor member functions to get the geometry for each class.

Since we don't have access to a C++ 2D graphics library in class, the derived draw functions will not actually draw the geometry on the monitor. Instead, implement draw so it outputs the geometry in text format to a stream.

Use the following unit test as a starting point to validate your implementation:

#include "TestHarness.h"

#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"

#include <memory>
#include <sstream>

TEST(drawUnique, Shape)
{
    std::vector<std::unique_ptr<Shape>> shapes;

    std::stringstream canvas;

    shapes.push_back(std::make_unique<Rectangle>(Point(11.1, 22.2), Point(33.3, 44.4), canvas));
    shapes.push_back(std::make_unique<Circle>(Point(111.1, 222.2), 333.3, canvas));

    for (auto& shape: shapes)
    {
        shape->draw();
    }

    CHECK_EQUAL("draw rectangle: 11.1,22.2,33.3,44.4draw circle: 111.1,222.2,333.3", canvas.str());
}
Shape Operators
Extend each of your shape classes with the following operators:

Addition (+) and add-and-assign (+=) operators which shift the position of the shape by the value of a given Point.
Subtraction (-) and subtract-and-assign (-=) operators which shift the position of the shape by the negative value of a given point.
A unary negation operator (different from subtraction) which negates the points contained within the shape. For example, the point (1, 1) becomes (-1, -1) after negation.
Comparison operators (== and !=) returning whether the two shapes are equivalent.
[Circle only] A multiplication (*) operator which scales the radius of the circle by the value of a given double.
Be sure to carefully consider which operators should modify the shape in-place and which operators should instead return an independent copy.

