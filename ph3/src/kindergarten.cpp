#include "kindergarten.h"
#include "teacher.h"

kindergarten::kindergarten(float l, float w, person m, string c, string s, string a, int p)
{
    setLength(l);
    setWidth(w);
    setManager(m);
    setAddress(c, s, a, p);
}

void kindergarten::setLength(float l)
{
    if (l < 0)
        throw invalid_argument("length can not be negative.");
    length = l;
}

void kindergarten::setWidth(float w)
{
    if (w < 0)
        throw invalid_argument("Width can not be negative.");
    width = w;
}

void kindergarten::setManager(person m)
{
    if (manager == nullptr)
        manager = new person(m);
    else
    {
        int temp;
        cout << "Enter security code : ";
        cin >> temp;
        if (temp == securityCode)
            manager = &m;
        else
            cerr << "Security code is wrong." << endl;
    }
}

void kindergarten::setAddress(string c, string s, string a, int p)
{
    if (p < 0)
        throw invalid_argument("Plaque can not be negative.");
    plaque = p;
    city = c;
    street = s;
    alley = a;
}

void kindergarten::addTeacher(teacher t)
{
    if (Teacher.size() > teacherCapacity)
        throw out_of_range("Full teacher capacity.");
    Teacher.push_back(new teacher(t));
}

void kindergarten::addChild(child ch)
{
    if (childs.size() > childsCapacity)
        throw out_of_range("Full child capacity.");
    childs.push_back(new child(ch));
}

void kindergarten::addDevice(device d)
{
    int sum = 0;
    for (int i = 0; i < devices.size(); i++)
        sum += devices[i]->getLength() * devices[i]->getWidth();
    for (int i = 0; i < books.size(); i++)
        sum += books[i]->getLength() * books[i]->getWidth();
    if (sum > length * width / 2)
        throw out_of_range("We have nowhere in the nursery to put the device.");
    devices.push_back(new device(d));
}

void kindergarten::addBook(book b)
{
    int sum = 0;
    for (int i = 0; i < devices.size(); i++)
        sum += devices[i]->getLength() * devices[i]->getWidth();
    for (int i = 0; i < books.size(); i++)
        sum += books[i]->getLength() * books[i]->getWidth();
    if (sum > length * width / 2)
        throw out_of_range("We have nowhere in the nursery to put the book.");
    books.push_back(new book(b));
}

float kindergarten::getLength() const
{
    return length;
}
float kindergarten::getWidth() const
{
    return width;
}

string kindergarten::getManager() const
{
    return manager->getFname() + ' ' + manager->getLname();
}

string kindergarten::getAddress() const
{
    return city + ", " + street + ", " + alley + ", " + to_string(plaque);
}

void kindergarten::removeTeacher(ulli nc)
{
    for (int i = 0; i < Teacher.size(); i++)
        if (Teacher[i]->getNationalCode() == nc)
        {
            Teacher.erase(Teacher.begin() + i);
            cout << "Done." << endl;
            return;
        }
    throw logic_error("There is no such teacher in this kindergarten.");
}

void kindergarten::removeChild(ulli nc)
{
    for (int i = 0; i < childs.size(); i++)
        if (childs[i]->getNationalCode() == nc)
        {
            childs.erase(childs.begin() + i);
            cout << "Done." << endl;
            return;
        }
    throw logic_error("There is no such childs in this kindergarten.");
}

void kindergarten::removeDevice(int i)
{
    for (int i = 0; i < devices.size(); i++)
        if (devices[i]->getId() == i)
        {
            devices.erase(devices.begin() + i);
            cout << "Done." << endl;
            return;
        }
    throw logic_error("There is no such device in this kindergarten.");
}

void kindergarten::removeBook(int i)
{
    for (int i = 0; i < books.size(); i++)
        if (books[i]->getId() == i)
        {
            books.erase(books.begin() + i);
            cout << "Done." << endl;
            return;
        }
    throw logic_error("There is no such book in this kindergarten.");
}
