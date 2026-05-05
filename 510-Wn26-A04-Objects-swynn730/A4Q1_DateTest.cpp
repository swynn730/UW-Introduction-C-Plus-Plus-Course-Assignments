#include "TestHarness.h"
#include "A4Q1_Date.h"


// ================================================================
TEST(oneDaySuccessfullyAdded, addOneDay)
{
    const Date originalDate = {2026, 2, 13};
    Date updatedDate = addOneDay(originalDate);
    CHECK_EQUAL(2026, updatedDate.year);
    CHECK_EQUAL(2, updatedDate.month);
    CHECK_EQUAL(14, updatedDate.day);
}

TEST(oneDaySuccessfullyAddedLastDayOfMonth, addOneDay)
{
    const Date originalDate = {2026, 4, 30};
    Date updatedDate = addOneDay(originalDate);
    CHECK_EQUAL(2026, updatedDate.year);
    CHECK_EQUAL(5, updatedDate.month);
    CHECK_EQUAL(1, updatedDate.day);
}

TEST(oneDaySuccessfullyAddedLeap, addOneDay)
{
    // 2024 is a leap year but adding 1 to the 29th of February should rollover.
    const Date originalDate = {2024, 2, 29};
    Date updatedDate = addOneDay(originalDate);
    CHECK_EQUAL(2024, updatedDate.year);
    CHECK_EQUAL(3, updatedDate.month);
    CHECK_EQUAL(1, updatedDate.day);
}

TEST(oneDaySuccessfullyAddedNoLeap, addOneDay)
{
    const Date originalDate = {2023, 2, 28};
    Date updatedDate = addOneDay(originalDate);
    CHECK_EQUAL(2023, updatedDate.year);
    CHECK_EQUAL(3, updatedDate.month);
    CHECK_EQUAL(1, updatedDate.day);
}
// ================================================================

// ================================================================
TEST(oneMonthSuccessfullyAdded, addOneMonth)
{
    const Date originalDate = {2026, 1, 14};
    Date updatedDate = addOneMonth(originalDate);
    CHECK_EQUAL(2026, updatedDate.year);
    CHECK_EQUAL(2, updatedDate.month);
    CHECK_EQUAL(14, updatedDate.day);
}

TEST(oneMonthSuccessfullyAddedLastMonthOfYear, addOneMonth)
{
    const Date originalDate = {2026, 12, 25};
    Date updatedDate = addOneMonth(originalDate);
    CHECK_EQUAL(2027, updatedDate.year);
    CHECK_EQUAL(1, updatedDate.month);
    CHECK_EQUAL(25, updatedDate.day);
}

TEST(oneMonthSuccessfullyAddedLeap, addOneMonth)
{
    // 2024 is a leap year hence the 29th of February.
    const Date originalDate = {2024, 2, 29};
    Date updatedDate = addOneMonth(originalDate);
    CHECK_EQUAL(2024, updatedDate.year);
    CHECK_EQUAL(3, updatedDate.month);
    CHECK_EQUAL(29, updatedDate.day);
}

TEST(oneMonthSuccessfullyAddedFromMonthMoreDaysToLessDays, addOneMonth)
{
    const Date originalDate = {2023, 3, 31};
    Date updatedDate = addOneMonth(originalDate);
    CHECK_EQUAL(2023, updatedDate.year);
    CHECK_EQUAL(4, updatedDate.month);
    CHECK_EQUAL(30, updatedDate.day);
}
// ================================================================

// ================================================================
TEST(oneYearSuccessfullyAdded, addOneYear)
{
    const Date originalDate = {2026, 11, 10};
    Date updatedDate = addOneYear(originalDate);
    CHECK_EQUAL(2027, updatedDate.year);
    CHECK_EQUAL(11, updatedDate.month);
    CHECK_EQUAL(10, updatedDate.day);
}

TEST(oneYearSuccessfullyAddedLeap, addOneYear)
{
    // 2020 is a leap year but NOT 2021.
    const Date originalDate = {2020, 2, 29};
    Date updatedDate = addOneYear(originalDate);
    CHECK_EQUAL(2021, updatedDate.year);
    CHECK_EQUAL(2, updatedDate.month);
    CHECK_EQUAL(28, updatedDate.day);
}
// ================================================================