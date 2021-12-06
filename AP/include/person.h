#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

typedef unsigned long long int ulli;

using namespace std;

class person
{
public:
    person(string, string, int, bool, ulli);

    void setFname(string);
    void setLname(string);
    virtual void setAge(int);
    void setGender(bool);
    void setNationalCode(ulli);

    string getFname() const;
    string getLname() const;
    int getAge() const;
    string getGender() const;
    ulli getNationalCode() const;

    friend ostream &operator<<(ostream &out, const person &p)
    {
        cout << "Person name : " << p.Fname << ' ' << p.Lname << endl
             << "Person age : " << p.age << endl;
        string temp = (p.gender == true) ? "girl" : "boy";
        cout << "Person gender : " << temp << endl
             << "Person national code : " << p.nationalCode << endl;
        return out;
    }

private:
    string Fname, Lname; // First & Last name
    int age;
    bool gender; // true = girl & false = boy
    ulli nationalCode;
};

#endif