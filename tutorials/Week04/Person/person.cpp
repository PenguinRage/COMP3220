#include "person.h"
#include <string>

namespace Week4 {

Person::Person(const std::string& firstName,
               const std::string& surname,
               const Date& dateOfBirth) :
    m_firstName(firstName),
    m_surname(surname),
    m_dateOfBirth(dateOfBirth)
{}

Person::~Person(){
    // nothing happens
}

void Person::changeFirstName(const std::string &firstName)
{
    m_firstName = firstName;
}

void Person::changeSurname(const std::string &surname)
{
    m_surname = surname;
}

const std::string& Person::getFirstName() const {
    return m_firstName;
}

const std::string& Person::getSurname() const {
    return m_surname;
}

int Person::getYearOfBirth() {
    return m_dateOfBirth.getYear();
}

bool Person::isBornInLeapYear() {
    int year = getYearOfBirth();
    return year%400==0 || (year%4==0 && year%100!=0);
}
}
