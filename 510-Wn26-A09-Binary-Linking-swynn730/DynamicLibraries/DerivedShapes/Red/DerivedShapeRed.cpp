#include "DerivedShape.h"


Rectangle::Rectangle()
    : Shape(Color::Red)
{
}

Rectangle::~Rectangle() = default;

int MeaningOfLife()
{
    return 42;
}

extern "C" DERIVEDSHAPE_API Rectangle* Rectangle_createRectangle_red()
{
    return new Rectangle();
}

extern "C" DERIVEDSHAPE_API int Rectangle_getColor_red(Rectangle* r)
{
    return static_cast<int>(r->getColor());
}

extern "C" DERIVEDSHAPE_API void Rectangle_destroyRectangle_red(Rectangle* r)
{
    delete r;
}