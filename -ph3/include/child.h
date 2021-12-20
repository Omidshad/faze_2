#ifndef CHILD_H
#define CHILD_H

#include "person.h"

class child : public person
{
public:
    enum class Problem
    {
        None,
        Maim,
        Pulmonary,
        Cancer,
        Eye
    };

    child(string, string, int, bool, ulli, // dad
          string, Problem);                // this

    void setFatherName(string);
    void setProblem(Problem);
    virtual void setAge(int) override;

    string getFatherName() const;
    string getProblem() const;

    void printProblems() const;

    friend ostream &operator<<(ostream &out, const child &ch)
    {
        person temp = ch;
        cout << temp; // call dad functiuon
        cout << "Child father name : " << ch.fatherName << endl
             << "Child problem : " << ch.getProblem() << endl;
        return out;
    }

private:
    string fatherName;
    Problem problem;
};

#endif