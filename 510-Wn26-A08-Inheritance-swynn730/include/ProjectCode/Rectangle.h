#pragma once

#include "Shape.h"
#include "Point.h"


class Rectangle : public Shape
{
public:
	explicit Rectangle(Point upper_left, Point lower_right, std::ostream& os);
    
    void draw() const override;
	void stream(std::ostream& os) const override;

	Point get_upper_left() const;
	Point get_lower_right() const;
	std::array<Point, 2> get_dimensions() const;

	void set_upper_left(Point upper_left);
	void set_lower_right(Point lower_right);
	void set_dimensions(Point upper_left, Point lower_right);

	Rectangle& operator+=(const Point& point);
    Rectangle operator+(const Point& point) const;

	Rectangle& operator-=(const Point& point);
    Rectangle operator-(const Point& point) const;

	Rectangle operator-() const;

	bool operator==(const Rectangle& otherRectangle) const;
	bool operator!=(const Rectangle& otherRectangle) const;

private:
    std::array<Point, 2> dimensions{Point{0.0f, 0.0f}, Point{0.0f, 0.0f}};
};