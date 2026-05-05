#pragma once

#include "ProjectCode_API.h"
#include <array>
#include <ostream>


class Point
{
public:

	// On Windows, at least one API must be exported in order for a library to be
	// generated. Without this, UnitTestExe will complain about ProjectCode.lib
	// not existing, which thwarts building this starter code out of the box.
	//
	explicit Point(float x, float y);

	void stream(std::ostream& os) const;

	float get_x() const;
	float get_y() const;
	std::array<float, 2> get_components() const;
	 
	void set_x(float x);
	void set_y(float y);
	void set_components(float x, float y);

private:
	std::array<float, 2> components{0.0f, 0.0f};
};

inline std::ostream& operator<<(std::ostream& os, const Point& point)
{
    point.stream(os);
    return os;
}