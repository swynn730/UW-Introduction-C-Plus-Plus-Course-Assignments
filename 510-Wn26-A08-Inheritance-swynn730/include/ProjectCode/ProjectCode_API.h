#pragma once

#ifdef _WIN32
  //This is a common pattern for Windows DLLs, which, by default, do NOT export any definitions outside of the DLL.
  #ifdef PROJECTCODEDLL_EXPORTS
    //PROJECTCODEDLL_EXPORTS will be defined in the "preprocessor definitions" section of the .vcxproj file for the DLL.
    //Thus, it'll be defined when building the DLL itself, and so the PROJECTCODEDLL_API will be replaced, by the preprocessor,
    //with "__declspec(dllexport)", which tells the linker that the class (or function) should be exported from the DLL.
    #define PROJECTCODE_API __declspec(dllexport)
  #else
    //But when the header file is included by client code, PROJECTCODEDLL_EXPORTS will not be defined, so "__declspec(dllimport)"
    //will be substituted by the preprocessor instead - so the actual class/function will be looked for in the dynamically-linked library.
    #define PROJECTCODE_API __declspec(dllimport)
  #endif
#else
  //Note that this does not apply for Linux/Unix environments;
  //.so "shared object" libraries export everything by default. So we'll just preprocessor-define this to nothing.
  #define PROJECTCODE_API 
#endif
