#ifndef KINDERGARTEN_H
#define KINDERGARTEN_H

#include "person.h"
#include "device.h"
#include "teacher.h"
#include "child.h"
#include "book.h"
#include <vector>

class kindergarten
{
public:
    kindergarten(float, float, person, string, string, string, int);

    void setLength(float);
    void setWidth(float);
    void setManager(person);
    void setAddress(string, string, string, int);

    void addTeacher(teacher);
    void addChild(child);
    void addDevice(device);
    void addBook(book);

    float getLength() const;
    float getWidth() const;
    string getManager() const;
    string getAddress() const;

    void removeTeacher(ulli);
    void removeChild(ulli);
    void removeDevice(int);
    void removeBook(int);

    friend ostream &operator<<(ostream &out, const kindergarten &p)
    {
        cout << "kindergarten manager : " << p.getManager() << endl
             << "kindergarten address : " << p.getAddress() << endl;
        
        cout << "kindergarten teachers : " << endl;
        for (int i = 0; i < p.Teacher.size(); i++)
            cout << *p.Teacher[i] << endl;
        cout << endl;
        
        cout << "kindergarten childs : " << endl;
        for (int i = 0; i < p.childs.size(); i++)
            cout << *p.childs[i] << endl;
        cout << endl;
        
        cout << "kindergarten devices : " << endl;
        for (int i = 0; i < p.devices.size(); i++)
            cout << *p.devices[i] << endl;
        cout << endl;
        
        cout << "kindergarten books : " << endl;
        for (int i = 0; i < p.books.size(); i++)
            cout << *p.books[i] << endl;
        cout << endl;

        return out;
    }

private:
    float length, width;
    person *manager = nullptr;

    vector<person *> Teacher;
    const int teacherCapacity = 5;

    vector<person *> childs;
    const int childsCapacity = 40;

    vector<device *> devices;
    vector<device *> books;

    // address
    string city, street, alley;
    int plaque;

    const int securityCode = 270773448; // for change manager
};

#endif