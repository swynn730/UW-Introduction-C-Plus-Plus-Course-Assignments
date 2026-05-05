#include "TestHarness.h"
#include <array>
#include <string>


#ifndef PROBLEM3_MONTHTABLE_H
#define PROBLEM3_MONTHTABLE_H
std::array<std::string, 12> Get_Months();

std::array<int, 12> Get_Number_Of_Days_Per_Month();

struct Month_And_Day_Struct {
    std::string month;
    int day;
};

std::array<Month_And_Day_Struct, 12> Months_And_Days;
#endif