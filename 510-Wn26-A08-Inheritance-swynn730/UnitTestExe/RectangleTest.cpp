#include "TestHarness.h"

#include "Rectangle.h"


TEST(construct, Rectangle)
{
    std::stringstream canvas;
    Rectangle r1{Point(0.0f, 0.0f), Point(2.0f, 1.0f), canvas};

    CHECK_EQUAL(0.0f, r1.get_upper_left().get_x());
    CHECK_EQUAL(0.0f, r1.get_upper_left().get_y());
    CHECK_EQUAL(2.0f, r1.get_lower_right().get_x());
    CHECK_EQUAL(1.0f, r1.get_lower_right().get_y());
}

TEST(draw, Rectangle)
{
    std::stringstream canvas;
    Rectangle r1{Point(0.0f, 0.0f), Point(2.0f, 1.0f), canvas};
    r1.draw();
    
    CHECK_EQUAL("RECTANGLE[POINT(0.0f, 0.0f), POINT(2.0f, 1.0f)]", canvas.str());
}

TEST(plusEqual, Rectangle)
{
    std::stringstream canvas;
    Rectangle r1{Point(0.0f, 0.0f), Point(2.0f, 1.0f), canvas};
    Point p1{1.0f, 1.0f};
    r1 += p1;
    CHECK_EQUAL(1.0f, r1.get_upper_left().get_x());
    CHECK_EQUAL(1.0f, r1.get_upper_left().get_y());
    CHECK_EQUAL(3.0f, r1.get_lower_right().get_x());
    CHECK_EQUAL(2.0f, r1.get_lower_right().get_y());
}

TEST(plus, Rectangle)
{
    std::stringstream canvas;
    Rectangle r1{Point(0.0f, 0.0f), Point(2.0f, 1.0f), canvas};
    Point p1{1.0f, 1.0f};
    Rectangle r2 = r1 + p1;
    CHECK_EQUAL(1.0f, r2.get_upper_left().get_x());
    CHECK_EQUAL(1.0f, r2.get_upper_left().get_y());
    CHECK_EQUAL(3.0f, r2.get_lower_right().get_x());
    CHECK_EQUAL(2.0f, r2.get_lower_right().get_y());
}

TEST(minusEqual, Rectangle)
{
    std::stringstream canvas;
    Rectangle r1{Point(0.0f, 0.0f), Point(2.0f, 1.0f), canvas};
    Point p1{1.0f, 1.0f};
    r1 -= p1;
    CHECK_EQUAL(-1.0f, r1.get_upper_left().get_x());
    CHECK_EQUAL(-1.0f, r1.get_upper_left().get_y());
    CHECK_EQUAL(1.0f, r1.get_lower_right().get_x());
    CHECK_EQUAL(0.0f, r1.get_lower_right().get_y());
}

TEST(minus, Rectangle)
{
    std::stringstream canvas;
    Rectangle r1{Point(0.0f, 0.0f), Point(2.0f, 1.0f), canvas};
    Point p1{1.0f, 1.0f};
    Rectangle r2 = r1 - p1;
    CHECK_EQUAL(-1.0f, r2.get_upper_left().get_x());
    CHECK_EQUAL(-1.0f, r2.get_upper_left().get_y());
    CHECK_EQUAL(1.0f, r2.get_lower_right().get_x());
    CHECK_EQUAL(0.0f, r2.get_lower_right().get_y());
}

TEST(unary, Rectangle)
{
    std::stringstream canvas;
    Rectangle r1{Point(0.0f, 0.0f), Point(2.0f, 1.0f), canvas};
    Rectangle r2 = -r1;
    CHECK_EQUAL(-0.0f, r2.get_upper_left().get_x());
    CHECK_EQUAL(-0.0f, r2.get_upper_left().get_y());
    CHECK_EQUAL(-2.0f, r2.get_lower_right().get_x());
    CHECK_EQUAL(-1.0f, r2.get_lower_right().get_y());
}

TEST(equal, Rectangle)
{
    std::stringstream canvas;
    Rectangle r1{Point(0.0f, 0.0f), Point(2.0f, 1.0f), canvas};
    Rectangle r2{Point(0.0f, 0.0f), Point(2.0f, 1.0f), canvas};
    CHECK(r1 == r2);
}

TEST(notEqual, Rectangle)
{
    std::stringstream canvas;
    Rectangle r1{Point(0.0f, 0.0f), Point(2.0f, 1.0f), canvas};
    Rectangle r2{Point(1.0f, 0.0f), Point(2.0f, 1.0f), canvas};
    CHECK(r1 != r2);
}