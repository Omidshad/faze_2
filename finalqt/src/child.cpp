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
        throw out_of_range("No Problem available.");
    problem = p;
}

void child::setAge(int a)
{
    if (a < 0)
        throw invalid_argument("Age can not be negative.");
    else if (a > 5)
        throw out_of_range("Age is big.");
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