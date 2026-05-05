#include "Test.h"

#include "DerivedShape.h"
#include "dlfcn.h"
#include <iostream>
#include "Shape.h"


TEST(checkColorRed, Shape)
{
    auto myLibrary = dlopen("./Red/libDerivedShapes.so", RTLD_LOCAL | RTLD_LAZY);
    if (myLibrary == nullptr)
    {
        std::cout << "Error loading library!" << std::endl;
    }
    else
    {
        auto createRectangle = reinterpret_cast<Rectangle* (*)()>(dlsym(myLibrary, "Rectangle_createRectangle_red"));
        auto getColor = reinterpret_cast<int(*)(Rectangle*)>(dlsym(myLibrary, "Rectangle_getColor_red"));
        auto destroyRectangle = reinterpret_cast<void(*)(Rectangle*)>(dlsym(myLibrary, "Rectangle_destroyRectangle_red"));
        int color = -1;

        if (createRectangle && getColor && destroyRectangle)
        {
            Rectangle* r = createRectangle();
            color = getColor(r);
            destroyRectangle(r);
        }
        CHECK_EQUAL(0, color);
        dlclose(myLibrary);
    }
}

TEST(checkColorBlue, Shape)
{
    auto myLibrary = dlopen("./Blue/libDerivedShapes.so", RTLD_LOCAL | RTLD_LAZY);
    if (myLibrary == nullptr)
    {
        std::cout << "Error loading library!" << std::endl;
    }
    else
    {
        auto createRectangle = reinterpret_cast<Rectangle* (*)()>(dlsym(myLibrary, "Rectangle_createRectangle_blue"));
        auto getColor = reinterpret_cast<int(*)(Rectangle*)>(dlsym(myLibrary, "Rectangle_getColor_blue"));
        auto destroyRectangle = reinterpret_cast<void(*)(Rectangle*)>(dlsym(myLibrary, "Rectangle_destroyRectangle_blue"));
        int color = -1;

        if (createRectangle && getColor && destroyRectangle)
        {
            Rectangle* r = createRectangle();
            color = getColor(r);
            destroyRectangle(r);
        }
        CHECK_EQUAL(1, color);
        dlclose(myLibrary);
    }    
}

TEST(checkNumberRed, Shape)
{
    auto myLibrary = dlopen("./Red/libDerivedShapes.so", RTLD_LOCAL | RTLD_LAZY);
    if (myLibrary == nullptr)
    {
        std::cout << "Error loading library!" << std::endl;;
    }
    else
    {
        auto MeaningOfLife = reinterpret_cast<int(*)()>(dlsym(myLibrary, "MeaningOfLife"));
        const auto result = MeaningOfLife();
        CHECK_EQUAL(42, result);
        dlclose(myLibrary);
    }
}

TEST(checkNumberBlue, Shape)
{
    auto myLibrary = dlopen("./Blue/libDerivedShapes.so", RTLD_LOCAL | RTLD_LAZY);
    if (myLibrary == nullptr)
    {
        std::cout << "Error loading library!" << std::endl;;
    }
    else
    {
        auto MeaningOfLife = reinterpret_cast<int(*)()>(dlsym(myLibrary, "MeaningOfLife"));
        const auto result = MeaningOfLife();
        CHECK_EQUAL(47, result);
        dlclose(myLibrary);
    }
}