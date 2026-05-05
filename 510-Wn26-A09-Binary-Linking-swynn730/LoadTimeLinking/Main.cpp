#include "TestHarness.h"
#include <iostream>
#include "dlfcn.h"
#include <DerivedShape.h>


int main()
{
    std::cout << "Enter a color 'red' or 'blue':";
    std::string userColor;
    std::cin >> userColor;
    int color = -1;
    
    std::string shape_path;
    std::string color_suffix;
    if (userColor == "red")
    {
        shape_path = "./Red/libDerivedShapes.so";
        color_suffix = "red";
    }
    else if (userColor == "blue")
    {
        shape_path = "./Blue/libDerivedShapes.so";
        color_suffix = "blue";
    }
    else
    {
        std::cout << "Invalid color!" << std::endl;
    }

    void* myLibrary = dlopen(shape_path.c_str(), RTLD_LOCAL | RTLD_LAZY);
    if (!myLibrary)
    {
        std::cout << "dlopen error: " << dlerror() << std::endl;
        dlclose(myLibrary);
    }
    else
    {
        std::string createRectangleSymbolName = "Rectangle_createRectangle_" + color_suffix;
        std::string getColorSymbolName = "Rectangle_getColor_" + color_suffix;
        std::string destroyRectangleSymbolName = "Rectangle_destroyRectangle_" + color_suffix;

        auto createRectangle = reinterpret_cast<Rectangle* (*)()>(
            dlsym(myLibrary, createRectangleSymbolName.c_str()));

        auto getColor = reinterpret_cast<int (*)(Rectangle*)>(
            dlsym(myLibrary, getColorSymbolName.c_str()));

        auto destroyRectangle = reinterpret_cast<void (*)(Rectangle*)>(
            dlsym(myLibrary, destroyRectangleSymbolName.c_str()));

        if (!createRectangle || !getColor || !destroyRectangle)
        {
            std::cout << "dlsym error: " << dlerror() << std::endl;
            dlclose(myLibrary);
        }

        Rectangle* r = createRectangle();
        color = getColor(r);
        destroyRectangle(r);

        dlclose(myLibrary);

        if(color == 0) 
        {
            std::cout << "Red rectangle created!" << std::endl;
        }
        else if (color == 1) 
        {
            std::cout << "Blue rectangle created!" << std::endl;

        }
    }

    TestResult tr;
    TestRegistry::runAllTests(tr);

    return 0;
}