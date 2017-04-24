#include "date.h"

using namespace std;
namespace Week4 {

Date::Date(int day, int month, int year) :
    m_day(day),
    m_month(month),
    m_year(year)
{

}

Date::~Date()
{
    // nothing needed
}

int Date::getDay() const
{
    return m_day;
}

int Date::getMonth() const
{
    return m_month;
}

int Date::getYear() const
{
    return m_year;
}

// number is greater than 0 print "" else "0"
inline string prependZero(int num)
{
    return num > 0 ? "" : "0";
}

// Print to stream
std::string Date::dateAsString() const
{
    stringstream ss;
    int d = getDay();
    int m = getMonth();
    int y = getYear();

    ss << prependZero(d/10) << d
       << "/" << prependZero(m/10) << m
       << "/" << prependZero(y/1000)
       << prependZero(y/100)
       << prependZero(y/10) << y;

    return ss.str();
}

}
