#pragma once

#include "Shape.h"
#include "Point.h"


class Circle : public Shape
{
public:
	explicit Circle(Point origin, float radius, std::ostream& os);

    void draw() const override;
    void stream(std::ostream& os) const override;

	Point get_origin() const;
    float get_radius() const;

	void set_origin(Point p1); 
	void set_radius(float r);

	Circle& operator+=(const Point& point);
    Circle operator+(const Point& point) const;

	Circle& operator-=(const Point& point);
    Circle operator-(const Point& point) const;

	Circle operator-() const;

	bool operator==(const Circle& otherRectangle) const;
	bool operator!=(const Circle& otherRectangle) const;

    Circle operator*(double value) const;

private:
    Point origin = Point{0.0f, 0.0f};
    float radius = 0.0f;
};