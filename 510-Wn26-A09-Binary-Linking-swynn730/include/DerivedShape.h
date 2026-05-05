#pragma once

#include "Shape.h"

#ifdef WINDOWS
#ifdef DERIVED_EXPORTS
#define DERIVEDSHAPE_API __declspec(dllexport)
#else
#define DERIVEDSHAPE_API __declspec(dllimport)
#endif
#else
#define DERIVEDSHAPE_API
#endif

class Rectangle final : public Shape
{
public:
    DERIVEDSHAPE_API Rectangle();
    DERIVEDSHAPE_API ~Rectangle() override;

    Rectangle(const Rectangle&) = delete;
    Rectangle(Rectangle&&) = delete;
    Rectangle& operator=(const Rectangle&) = delete;
    Rectangle& operator=(Rectangle&&) = delete;
};

extern "C" {
    DERIVEDSHAPE_API int MeaningOfLife();
}