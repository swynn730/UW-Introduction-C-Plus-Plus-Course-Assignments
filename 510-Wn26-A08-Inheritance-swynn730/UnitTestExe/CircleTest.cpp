#include "TestHarness.h"

#include "Circle.h"


TEST(construct, Circle)
{
    std::stringstream canvas;
    Circle c1{Point(0.0f, 0.0f), 10.0f, canvas};

    CHECK_EQUAL(0.0f, c1.get_origin().get_x());
    CHECK_EQUAL(0.0f, c1.get_origin().get_y());
    CHECK_EQUAL(10.0f, c1.get_radius());
}

TEST(draw, Circle)
{
    std::stringstream canvas;
    Circle c1{Point(0.0f, 0.0f), 10.0f, canvas};
    c1.draw();

    CHECK_EQUAL("CIRCLE[POINT(0.0f, 0.0f), 10.0f]", canvas.str());
}

TEST(plusEqual, Circle)
{
    std::stringstream canvas;
    Circle c1{Point(0.0f, 0.0f), 5.0f, canvas};
    Point p1{1.0f, 1.0f};
    c1 += p1;
    CHECK_EQUAL(1.0f, c1.get_origin().get_x());
    CHECK_EQUAL(1.0f, c1.get_origin().get_y());
    CHECK_EQUAL(5.0f, c1.get_radius());
}

TEST(plus, Circle)
{
    std::stringstream canvas;
    Circle c1{Point(0.0f, 0.0f), 5.0f, canvas};
    Point p1{1.0f, 1.0f};
    Circle c2 = c1 + p1;
    CHECK_EQUAL(1.0f, c2.get_origin().get_x());
    CHECK_EQUAL(1.0f, c2.get_origin().get_y());
    CHECK_EQUAL(5.0f, c1.get_radius());
}

TEST(minusEqual, Circle)
{
    std::stringstream canvas;
    Circle c1{Point(0.0f, 0.0f), 5.0f, canvas};
    Point p1{1.0f, 1.0f};
    c1 -= p1;
    CHECK_EQUAL(-1.0f, c1.get_origin().get_x());
    CHECK_EQUAL(-1.0f, c1.get_origin().get_y());
    CHECK_EQUAL(5.0f, c1.get_radius());
}

TEST(minus, Circle)
{
    std::stringstream canvas;
    Circle c1{Point(0.0f, 0.0f), 5.0f, canvas};
    Point p1{1.0f, 1.0f};
    Circle c2 = c1 - p1;
    CHECK_EQUAL(-1.0f, c2.get_origin().get_x());
    CHECK_EQUAL(-1.0f, c2.get_origin().get_y());
    CHECK_EQUAL(5.0f, c1.get_radius());
}

TEST(unary, Circle)
{
    std::stringstream canvas;
    Circle c1{Point(5.0f, 5.0f), 5.0f, canvas};
    Circle c2 = -c1;
    CHECK_EQUAL(-5.0f, c2.get_origin().get_x());
    CHECK_EQUAL(-5.0f, c2.get_origin().get_y());
    CHECK_EQUAL(5.0f, c1.get_radius());
}

TEST(equal, Circle)
{
    std::stringstream canvas;
    Circle c1{Point(0.0f, 0.0f), 5.0f, canvas};
    Circle c2{Point(0.0f, 0.0f), 5.0f, canvas};
    CHECK(c1 == c2);
}

TEST(notEqual, Circle)
{
    std::stringstream canvas;
    Circle c1{Point(0.0f, 0.0f), 5.0f, canvas};
    Circle c2{Point(1.0f, 1.0f), 10.0f, canvas};
    CHECK(c1 != c2);
}

TEST(multiply, Circle)
{
    std::stringstream canvas;
    Circle c1{Point(0.0f, 0.0f), 5.0f, canvas};
    Circle c2 = c1 * 3.0f;
    CHECK_EQUAL(0.0f, c2.get_origin().get_x());
    CHECK_EQUAL(0.0f, c2.get_origin().get_y());
    CHECK_EQUAL(15.0f, c2.get_radius());
}