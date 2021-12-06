#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string>

using namespace std;

class device
{
public:
    enum class Color
    {
        Black,
        Blue,
        Red,
        Green,
        White,
        Silver,
        Yellow
    };
    enum class Gender
    {
        Wooden,
        Metal,
        Plastic,
        Paper,
        Fabric
    };

    device(int, float, string, Color, Gender, float, float, float);

    void setId(int);
    void setPrice(float);
    void setName(string);
    void setColor(Color);
    void setGender(Gender);
    void setWeight(float);
    void setLength(float);
    void setWidth(float);

    int getId() const;
    float getPrice() const;
    string getName() const;
    string getColor() const;
    string getGender() const;
    float getWeight() const;
    float getLength() const;
    float getWidth() const;

    void printColors() const;
    void printGenders() const;

    friend ostream &operator<<(ostream &out, const device &d)
    {
        cout << "Device name : " << d.name << endl
             << "Device color : " << d.getColor() << endl
             << "Device gender : " << d.getGender() << endl
             << "Device weight : " << d.weight << endl
             << "Device length : " << d.length << endl
             << "Device width : " << d.width << endl
             << "Device Price : " << d.price << endl;
        return out;
    }

private:
    int id;
    float price;
    string name;
    Color color;
    Gender gender;
    float weight, length, width;
};

#endif