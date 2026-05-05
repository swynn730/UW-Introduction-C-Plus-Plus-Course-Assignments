#include <iosfwd>


#pragma once

struct Date
{
    int year;
    int month;
    int day;
};

Date addOneDay(const Date& date);

Date addOneMonth(const Date& date);

Date addOneYear(const Date& date);