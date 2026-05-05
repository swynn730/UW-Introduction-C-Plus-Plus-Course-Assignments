#include "DerivedShape.h"


Rectangle::Rectangle()
    : Shape(Color::Blue)
{
}

Rectangle::~Rectangle() = default;

int MeaningOfLife()
{
    return 47;
}

extern "C" DERIVEDSHAPE_API Rectangle* Rectangle_createRectangle_blue()
{
    return new Rectangle();
}

extern "C" DERIVEDSHAPE_API int Rectangle_getColor_blue(Rectangle* r)
{
    return static_cast<int>(r->getColor());
}

extern "C" DERIVEDSHAPE_API void Rectangle_destroyRectangle_blue(Rectangle* r)
{
    delete r;
}