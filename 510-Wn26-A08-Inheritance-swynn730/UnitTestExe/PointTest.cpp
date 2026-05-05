#include "TestHarness.h"

#include "Point.h"


TEST(construct, Point)
{
    Point p1{0.0f, 1.0f};

    CHECK_EQUAL(0.0f, p1.get_x());
    CHECK_EQUAL(1.0f, p1.get_y());
}

TEST(set, Point)
{
    Point p1{0.0f, 1.0f};
    p1.set_components(3.0f, 7.0f);

    CHECK_EQUAL(3.0f, p1.get_x());
    CHECK_EQUAL(7.0f, p1.get_y());
}