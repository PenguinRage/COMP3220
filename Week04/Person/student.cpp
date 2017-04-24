#include <sstream>
#include <string>
#include "student.h"

using namespace std;

namespace Week4
{
    Student::Student(const string &givenName,
                     const string &surname,
                     const Date &date,
                     const string &degree) :
        Person(givenName,surname,date),
        m_degree(new string(degree)),
        m_recordAccessed(0)
    {}

    Student::~Student(){
        delete m_degree;
    }

    string Student::getRecord() const {
        stringstream ss;
        ss << "Name: " << getFirstName() << " " << getSurname() << endl
           << "Date Of Birth: " << m_dateOfBirth.dateAsString() << endl
           << "Degree: " << *m_degree;

        return ss.str();

    }
}
