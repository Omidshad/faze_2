#include "book.h"

book::book(int I, float p, string n, Color c, Gender g, float W, float l, float w, // dad
           string a, int pa, ulli i, string pu) : device(I, p, n, c, g, W, l, w)
{
    setAuthor(a);
    setPages(pa);
    setISBN(i);
    setPublisher(pu);
}

void book::setAuthor(string a)
{
    author = a;
}

void book::setPages(int p)
{
    if (p < 0)
        throw invalid_argument("Pages can not be negative.");
    pages = p;
}

void book::setISBN(ulli i)
{
    if (i < 0)
        throw invalid_argument("ISBN can not be negative.");
    ISBN = i;
}

void book::setPublisher(string pu)
{
    publisher = pu;
}

string book::getAuthor() const
{
    return author;
}

int book::getPages() const
{
    return pages;
}

ulli book::getISBN() const
{
    return ISBN;
}

string book::getPublisher() const
{
    return publisher;
}
