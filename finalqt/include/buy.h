#ifndef BUY_H
#define BUY_H

#include <iostream>
#include <string>
#include <vector>

#include "device.h"
#include "book.h"

using namespace std;

class buy
{
public:
    void addDevice(device);
    void addBook(book);
    void removeDevice(int);
    void removeBook(int);

    friend ostream &operator<<(ostream &out, const buy &d)
    {
        cout << "Devices : " << endl;
        for (int i = 0; i < d.devices.size(); i++)
        {
            cout << d.devices[i]->getName() << endl;
        }
        cout << "Books : " << endl;
        for (int i = 0; i < d.books.size(); i++)
        {
            cout << d.books[i]->getName() << endl;
        }
        return out;
    }
    vector<device *> devices;
    vector<device *> books;

private:
};

#endif