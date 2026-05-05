#include "A4Q1_Date.h"

#include <stdexcept>
#include <ostream>
#include <chrono>


using namespace std::chrono;

// Helper function.
int prepareMonth(std::chrono::month month)
{
    return static_cast<int>(static_cast<unsigned int>((month)));
}

// Helper function.
int prepareDay(std::chrono::day day)
{
    return static_cast<int>(static_cast<unsigned int>((day)));
}

Date addOneDay(const Date& date) 
{
    year_month_day yearMonthDay = 
    {
        year{date.year}, 
        month{static_cast<unsigned>(date.month)},
        day{static_cast<unsigned>(date.day)}
    };

    sys_days sysDays{yearMonthDay};

    sysDays += days{1};

    yearMonthDay = {sysDays};
    
    return
    {
        .year = static_cast<int>(yearMonthDay.year()),
        .month = prepareMonth(yearMonthDay.month()),
        .day = prepareDay(yearMonthDay.day())
    };
}

Date addOneMonth(const Date& date) 
{
    year_month_day yearMonthDay = 
    {
        year{date.year}, 
        month{static_cast<unsigned>(date.month)},
        day{static_cast<unsigned>(date.day)}
    };

    yearMonthDay += months{1};
    
    if (!yearMonthDay.ok()) 
    {
        yearMonthDay = yearMonthDay.year() / yearMonthDay.month() / last;
    }

    return
    {
        .year = static_cast<int>(yearMonthDay.year()),
        .month = prepareMonth(yearMonthDay.month()),
        .day = prepareDay(yearMonthDay.day())
    };
}

Date addOneYear(const Date& date) 
{
    year_month_day yearMonthDay = 
    {
        year{date.year}, 
        month{static_cast<unsigned>(date.month)},
        day{static_cast<unsigned>(date.day)}
    };

    yearMonthDay += years{1};
    
    if (!yearMonthDay.ok()) 
    {
        yearMonthDay = yearMonthDay.year() / yearMonthDay.month() / last;
    }

    return
    {
        .year = static_cast<int>(yearMonthDay.year()),
        .month = prepareMonth(yearMonthDay.month()),
        .day = prepareDay(yearMonthDay.day())
    };
}