#include "buy.h"

void buy::addDevice(device d)
{
    devices.push_back(new device(d));
}

void buy::addBook(book b)
{
    books.push_back(new book(b));
}

void buy::removeDevice(int i)
{
    for (int i = 0; i < devices.size(); i++)
        if (devices[i]->getId() == i)
        {
            devices.erase(devices.begin() + i);
            cout << "Done." << endl;
            return;
        }
    throw logic_error("No device was found with this ID.");
}

void buy::removeBook(int i)
{
    for (int i = 0; i < books.size(); i++)
        if (books[i]->getId() == i)
        {
            books.erase(books.begin() + i);
            cout << "Done." << endl;
            return;
        }
    throw logic_error("No book was found with this ID.");
}
