#pragma once

#include <iosfwd>

#ifdef WINDOWS
#ifdef SHAPE_EXPORTS
#define SHAPE_API __declspec(dllexport)
#else
#define SHAPE_API __declspec(dllimport)
#endif
#else
#define SHAPE_API
#endif

enum class Color {
    Red,
    Blue,
    Transparent
};
class Shape
{
public:

    SHAPE_API Shape();
    SHAPE_API virtual ~Shape();

    Shape(const Shape& src) = delete;
    Shape& operator=(const Shape& rhs) = delete;
    Shape(Shape&& src) = delete;
    Shape& operator=(Shape&& rhs) = delete;

    SHAPE_API Color getColor() const;

protected:

    SHAPE_API explicit Shape(Color color);

    Color m_color = Color::Transparent;
};

SHAPE_API std::ostream& operator<<(std::ostream& out, const Shape& shape);
SHAPE_API std::ostream& operator<<(std::ostream& out, Color color);