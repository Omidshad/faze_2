#include "child.h"

child::child(string fn, string ln, int a, bool g, ulli nc,
             string Fn, Problem p) : person(fn, ln, a, g, nc)
{
    setFatherName(Fn);
    setProblem(p);
}

void child::setFatherName(string fn)
{
    fatherName = fn;
}

void child::setProblem(Problem p)
{
    if ((int)p < 0 || (int)p > 4) // search Problem
    {
        cout << "No Problem available." << endl;
        return;
    }
    problem = p;
}

void child::setAge(int a)
{
    if (a < 0)
    {
        cout << "Age can not be negative." << endl;
        return;
    }
    else if (a > 5)
    {
        cout << "Age is big." << endl;
        return;
    }
    this->setAge(a);
}

string child::getFatherName() const
{
    return fatherName;
}

string child::getProblem() const
{
    switch ((int)problem)
    {
    case 0:
        return "None";
    case 1:
        return "Maim";
    case 2:
        return "Pulmonary";
    case 3:
        return "Cancer";
    case 4:
        return "Eye";
    }
}

void child::printProblems() const
{
    cout << "Problems : " << endl;
    cout << "None" << endl
         << "Maim" << endl
         << "Pulmonary" << endl
         << "Cancer" << endl
         << "Eye" << endl;
}