#include "person.h"

person::person(string fn, string ln, int a, bool g, ulli nc)
{
    setFname(fn);
    setLname(ln);
    setAge(a);
    setGender(g);
    setNationalCode(nc);
}

void person::setFname(string fn)
{
    Fname = fn;
}

void person::setLname(string ln)
{
    Lname = ln;
}

void person::setAge(int a)
{
    if (a < 0)
    {
        cout << "Age can not be negative." << endl;
        return;
    }
    else if (a > 80)
    {
        cout << "Age is too big." << endl;
        return;
    }
    age = a;
}

void person::setGender(bool g)
{
    gender = g;
}

void person::setNationalCode(ulli nc)
{
    if (nc < 0)
    {
        cout << "National code can not be negative." << endl;
        return;
    }
    nationalCode = nc;
}

string person::getFname() const
{
    return Fname;
}

string person::getLname() const
{
    return Lname;
}

int person::getAge() const
{
    return age;
}

string person::getGender() const
{
    if (gender)
        return "gril";
    return "boy";
}

ulli person::getNationalCode() const
{
    return nationalCode;
}