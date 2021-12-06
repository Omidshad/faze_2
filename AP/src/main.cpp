#include "kindergarten.h"

int main()
{
    person manager("Omid", "Omidi", 25, 0, 1234567890);
    cout << manager << endl;
    kindergarten Kind(25, 35, manager, "Tehran", "Azadi", "Valiasr", 75);
    Kind.setManager(manager);
    teacher t1("Ehsan", "Ehsani", 22, 0, 9876543210, 22500);
    teacher t2("Mohadese", "Ehsani", 27, 1, 125483, 25000, 26);
    cout << t2 << endl;
    Kind.addTeacher(t1);
    Kind.addTeacher(t2);
    child ch1("Matin", "Matini", 3, 0, 1245789635, "Omid", child::Problem::None);
    cout << ch1 << endl;
    child ch2("Manije", "Matini", 4, 1, 1515242425, "Hossein", child::Problem::Maim);
    child ch3("Mahdi", "Matini", -2, 0, 3636363636, "Ali", child::Problem::Eye);
    Kind.addChild(ch1);
    Kind.addChild(ch2);
    device d(12, 5000, "Khamir Bazi", device::Color::Green, device::Gender::Plastic, 1, 1.5, 0.5);
    cout << d << endl;
    Kind.addDevice(d);
    book b(13, 15000, "Rang Amizi", book::Color::Green, device::Gender::Paper, 5, 5, 0.250, "Ali Hoshyar", 23, 1023456789012, "Amir Kabir");
    cout << b << endl;
    Kind.addBook(b);
    cout << Kind << endl;
    Kind.removeTeacher(9876543210);
    Kind.removeBook(15);
    cout << Kind << endl;
    return 0;
}