#include "device.h"

device::device(int i, float p, string n, Color c, Gender g, float W, float l, float w)
{
    setId(i);
    setPrice(p);
    setName(n);
    setColor(c);
    setGender(g);
    setWeight(W);
    setLength(l);
    setWidth(w);
}

void device::setId(int i)
{
    id = i;
}

void device::setPrice(float p)
{
    if (p < 0)
    {
        cout << "Price can not be negative." << endl;
        return;
    }
    price = p;
}

void device::setName(string n)
{
    name = n;
}

void device::setColor(Color c)
{
    if ((int)c < 0 || (int)c > 6) // search color
    {
        cout << "No color available." << endl;
        return;
    }
    color = c;
}

void device::setGender(Gender g)
{
    if ((int)g < 0 || (int)0 > 4) // search gender
    {
        cout << "Material not available." << endl;
        return;
    }
    gender = g;
}

void device::setWeight(float W)
{
    if (W < 0)
    {
        cout << "Weight can not be negative." << endl;
        return;
    }
    weight = W;
}

void device::setLength(float l)
{
    if (l < 0)
    {
        cout << "length can not be negative." << endl;
        return;
    }
    length = l;
}

void device::setWidth(float w)
{
    if (w < 0)
    {
        cout << "length can not be negative." << endl;
        return;
    }
    width = w;
}

int device::getId() const
{
    return id;
}
float device::getPrice() const
{
    return price;
}

string device::getName() const
{
    return name;
}

string device::getColor() const
{
    switch ((int)color)
    {
    case 0:
        return "Black";
    case 1:
        return "Blue";
    case 2:
        return "Red";
    case 3:
        return "Green";
    case 4:
        return "White";
    case 5:
        return "Silver";
    case 6:
        return "Yellow";
    }
}

string device::getGender() const
{
    switch ((int)gender)
    {
    case 0:
        return "Wooden";
    case 1:
        return "Metal";
    case 2:
        return "Plastic";
    case 3:
        return "Paper";
    case 4:
        return "Fabric";
    }
}

float device::getWeight() const
{
    return weight;
}

float device::getLength() const
{
    return length;
}

float device::getWidth() const
{
    return width;
}

void device::printColors() const
{
    cout << "Colors : " << endl;
    cout << "Black" << endl
         << "Blue" << endl
         << "Red" << endl
         << "Green" << endl
         << "White" << endl
         << "Silver" << endl
         << "Yellow" << endl;
}

void device::printGenders() const
{
    cout << "Genders : " << endl;
    cout << "Wooden" << endl
         << "Metal" << endl
         << "Plastic" << endl
         << "Paper" << endl
         << "Fabric" << endl;
}