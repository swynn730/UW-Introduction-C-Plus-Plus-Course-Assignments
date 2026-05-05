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

    shapes.push_back(std::make_unique<Rectangle>(Point(11.1f, 22.2f), Point(33.3f, 44.4f), canvas));
    shapes.push_back(std::make_unique<Circle>(Point(111.1f, 222.2f), 333.3f, canvas));

    for (const auto& shape: shapes)
    {
        shape->draw();
    }

    CHECK_EQUAL("RECTANGLE[POINT(11.1f, 22.2f), POINT(33.3f, 44.4f)]CIRCLE[POINT(111.1f, 222.2f), 333.3f]", canvas.str());
}