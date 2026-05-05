#include "TestHarness.h"
#include "Problem3_MonthTable.h"
#include <array>
#include <string>
#include <iostream>


std::array<std::string, 12> Get_Months() {
    std::array<std::string, 12> months = 
    {   "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"  };
    return months;
}

std::array<int, 12> Get_Number_Of_Days_Per_Month() {
    std::array<int, 12> number_of_days_per_month = 
    {   31, 28, 31, 30,
        31, 30, 31, 31,
        30, 31, 30, 31  };
    return number_of_days_per_month;
}

TEST(monthsMatchNumberOfDaysPerMonth, Get_Months_and_Get_Number_Of_Days_Per_Month)
{   
    auto Months_And_Days_Test_String = "January 31\nFebruary 28\nMarch 31\nApril 30\nMay 31\nJune 30\nJuly 31\nAugust 31\nSeptember 30\nOctober 31\nNovember 30\nDecember 31\n";
    auto months = Get_Months();
    auto days = Get_Number_Of_Days_Per_Month();
    std::stringstream stream;

    for(int i = 0; i < months.size(); i++){
        stream << months[i] << " " << days[i] << std::endl;
    }

    CHECK_EQUAL(Months_And_Days_Test_String, stream.str());
}

TEST(monthsMatchNumberOfDaysPerMonthUsingStruct, Months_And_Days_Struct)
{   
    auto Months_And_Days_Test_String = "January 31\nFebruary 28\nMarch 31\nApril 30\nMay 31\nJune 30\nJuly 31\nAugust 31\nSeptember 30\nOctober 31\nNovember 30\nDecember 31\n";
    std::array<Month_And_Day_Struct, 12> Months_And_Days = {{
        {"January", 31},
        {"February", 28},
        {"March", 31},
        {"April", 30},
        {"May", 31},
        {"June", 30},
        {"July", 31},
        {"August", 31},
        {"September", 30},
        {"October", 31},
        {"November", 30},
        {"December", 31}        
    }};
    
    std::stringstream stream;

    for(const auto &i: Months_And_Days){
        stream << i.month << " " << i.day << std::endl;
    }

    CHECK_EQUAL(Months_And_Days_Test_String, stream.str());
}