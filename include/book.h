#ifndef BOOK_H
#define BOOK_H

#include "device.h"

typedef unsigned long long int ulli;

class book : public device
{
public:
    book(int, float, string, Color, Gender, float, float, float, // dad
         string, int, ulli, string);                             // this

    void setAuthor(string);
    void setPages(int);
    void setISBN(ulli);
    void setPublisher(string);

    string getAuthor() const;
    int getPages() const;
    ulli getISBN() const;
    string getPublisher() const;

    friend ostream &operator<<(ostream &out, const book &b)
    {
        device temp = b;
        cout << temp; // call dad functiuon
        cout << "Book author : " << b.author << endl
             << "Book ISBN : " << b.ISBN << endl
             << "Book pages : " << b.pages << endl
             << "Book publisher : " << b.publisher << endl;
        return out;
    }

private:
    string author;
    int pages;
    ulli ISBN;
    string publisher;
};

#endif