#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"

class teacher : public person
{
public:
    teacher(string, string, int, bool, ulli, // dad
            float, float = 0);               // this

    void setSalary(float);
    void setWorkingHours(float);

    float getSalary() const;
    float getWorkingHours() const;

    float calculateRights() const;

    friend ostream &operator<<(ostream &out, const teacher &t)
    {
        person temp = t;
        cout << temp; // call dad functiuon
        cout << "teacher salary : " << t.salary << endl
             << "teacher working hours : " << t.workingHours << endl;
        return out;
    }

private:
    float salary, workingHours;
};

#endif