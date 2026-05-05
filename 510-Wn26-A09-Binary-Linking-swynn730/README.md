Static, Load-Time, and Run-Time Linking
Background
Code can be grouped into separate collections called "libraries".
These can be "linked" together:
    •   at build time (static linkages: Windows: Library ".lib"; Linux-like systems: Archive ".a")
    •   dynamically (Windows: Dynamic Link Library, ".dll"; Linux-like systems: Shared Object ".so")
        ◦   at program load time, via load directory search rules
        ◦   at program runtime, via an explicit call to load a specific library.

Load-Time Dynamic Linking
For this part of the assignment, you will create multiple implementations of a .dll/.so, and run different versions at runtime depending on load order rules.
Implement the following:
    •   Compile a Shape.dll/.so file.
    •   Provide an `enum class Color` with values `Red` and `Blue`.
    •   Add a protected Color member item to the Shape class and implement a public accessor that returns the value.
    •   (Windows only) Ensure that the Shape class's public member functions, and the Color enum, are exported via __declspec(dllexport) when building Shape.dll, and imported via __declspec(dllimport) when compiling code that uses Shape.h. See examples in Assignment 8 starter code and Lesson 9 materials.
    •   Create a DerivedShapes .dll/.so that provides an implementation of Rectangle, which sets Shape::m_color to be Color::Red.
    •   Create a different implementation of a DerivedShapes .dll/.so that provides an implementation of Rectangle, which sets Shape::m_color to be Color::Blue.
        ◦   Ensure that these 2 dll/so's are built to different directories.
    •   Both DerivedShapes .dll/.so's should expose a free function:
        ◦   `int MeaningOfLife()`
            ▪   The "red" .dll/.so should return 42.
            ▪   The "blue" one shall return some non-42 value of your choosing.
    •   Ensure that your project files / makefiles enforce build order dependency (you should be able to build all with ONE action).
    •   Investigate load order rules
        ◦   Windows: investigate DLL load rules ( https://learn.microsoft.com/en-us/windows/win32/dlls/dynamic-link-library-search-order)
        ◦   Linux: investigate .so load rules (Linux: https://tldp.org/HOWTO/Program-Library-HOWTO/shared-libraries.html)
    •   Create a LoadTimeLinkedShapes(.exe) which
        ◦   uses Shape and DerivedShapes libraries,
        ◦   runs unit tests verifying the color of a created Shape,
        ◦   runs unit tests verifying that `MeaningOfLife()` returns the expected value.
    •   Manipulate DLL location, environment variable, etc. to be able to run LoadTimeLinkedShapes(.exe) in two modes:
          1. The program finds and loads the "red" DerivedShapes.dll first, and verifies that a created Rectangle is red, and that `MeaningOfLife()` returns the expected value.
          2. The program finds and loads the "blue" DerivedShapes.dll first, and verifies that a created Rectangle is blue, and that `MeaningOfLife()` returns the expected value.
          The "manipulation" should not require re-compiling your LoadTimeLinkedShapes(.exe).

Run-Time Dynamic Linking
Investigate run-time dynamic linking OS API functions:
    •   Windows: investigate
        ◦   LoadLibrary (https://learn.microsoft.com/en-us/windows/win32/dlls/using-run-time-dynamic-linking)
        ◦   GetProcAddress (GetProcAddress function (libloaderapi.h) - Win32 apps | Microsoft Learn)
    •   Linux: investigate
        ◦   https://pubs.opengroup.org/onlinepubs/009695399/functions/dlopen.html
        ◦   https://pubs.opengroup.org/onlinepubs/009695399/functions/dlclose.html
        ◦   https://pubs.opengroup.org/onlinepubs/009695399/functions/dlsym.html
Create a RuntimeLinkedShapes(.exe) that asks the user whether to load the "red" or "blue" DerivedShapes.dll, and then demonstrates that it has done so by creating a Rectangle that is the appropriate color.

Static Linking
Create a different set of .vcxproj/makefile's that build Shape and one of the DerivedShapes libraries as static libraries (.lib/.a). You should be able to use the same source code. Do the following:
    •   Create a StaticallyLoadedShapes(.exe) that links to those static libraries.
    •   Ensure that your project files / makefiles enforce build order dependency (you should be able to build all with ONE action).
    •   Demonstrate that the resulting .exe can be run from anywhere, and does not depend on the existence of the corresponding .lib files.
