#include "teacher.h"

teacher::teacher(string fn, string ln, int a, bool g, ulli nc,
                 float s, float w) : person(fn, ln, a, g, nc)
{
    setSalary(s);
    setWorkingHours(w);
}

void teacher::setSalary(float s)
{
    if (s < 0)
    {
        cout << "Pages can not be negative." << endl;
        return;
    }
    salary = s;
}

void teacher::setWorkingHours(float w)
{
    workingHours = w;
}

float teacher::getSalary() const
{
    return salary;
}

float teacher::getWorkingHours() const
{
    return workingHours;
}

float teacher::calculateRights() const
{
    return salary * workingHours;
}