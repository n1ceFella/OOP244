//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           23.10.2021
//==============================================

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
#include "Book.h"
using namespace std;
namespace sdds
{
    Book::Book()
    {
    }
    Book::Book(const char* title, const char* authorName, int bookcaseNumber, int shelfNumber)
    {
        set(title, authorName, bookcaseNumber, shelfNumber);
    }
    //copy constructor
    Book::Book(const Book& book)
    {
        if (book) {
            *this = book;
        }
    }
    Book::~Book()
    {
        delete[] m_title;
        delete[] m_authorName;
    }
    //return true if not nullptr
    Book::operator bool() const
    {
        return m_authorName && m_title;
    }
    Book& Book::operator=(const Book& book)
    {
        if (this != &book) { //if not self copy
            set(book.m_title, book.m_authorName, book.m_bookcaseNumber, book.m_shelfNumber);
        }
        return *this;
    }
    //Book object setter
    void Book::set(const char* title, const char* authorName, int bookcaseNumber, int shelfNumber)
    {
        if ((title && title[0] != '\0') && 
            (authorName && authorName[0] != '\0') &&
            (bookcaseNumber > 0 && bookcaseNumber <= NoOfBookCases) &&
            (shelfNumber > 0 && shelfNumber <= NoOfShelves)) {
            allocateAndCopyTitle(title);
            allocateAndCopyAuthorName(authorName);
            m_shelfNumber = shelfNumber;
            m_bookcaseNumber = bookcaseNumber;
        }
        else {
            delete[] m_title;
            delete[] m_authorName;
            setEmpty();
        }
    }
    void Book::setEmpty()
    {
        m_title = nullptr;
        m_authorName = nullptr;
    }
    //DMA for author name
    void Book::allocateAndCopyAuthorName(const char* name)
    {
        delete[] m_authorName;
        m_authorName = new char[strlen(name) + 1];
        strcpy(m_authorName, name);
    }
    //DMA for title
    void Book::allocateAndCopyTitle(const char* name)
    {
        delete[] m_title;
        m_title = new char[strlen(name) + 1];
        strcpy(m_title, name);
    }
    //exctract redundant character
    void Book::extractChar(std::istream& istr, char ch) const
    {
        if (istr.peek() == ch) { // checking if the next character in keyboard same as ch
            istr.ignore();
        }
        else {
            istr.setstate(ios::failbit); //set istr to fail state
        }
    }
    //diplay formatted data
    ostream& Book::write(ostream& ostr, bool onScreen)const
    {
        if (onScreen) {
            if (*this) {
                ostr.setf(ios::left);
                ostr.width(40);
                ostr << m_title;
                ostr << "| ";
                ostr.width(24);
                ostr << m_authorName;
                ostr << " | ";
                ostr << m_shelfNumber << "/";
                ostr.unsetf(ios::left);
                ostr.setf(ios::right);
                ostr.fill('0');
                ostr.width(3);
                ostr << m_bookcaseNumber;
                ostr.unsetf(ios::right);
            }
            else {
                ostr.setf(ios::left);
                ostr.fill('.');
                ostr.width(39);
                ostr << "Invalid Book Record ";
                ostr << " | ";
                ostr.width(24);
                ostr << ".";
                ostr << " | ";
                ostr.width(5);
                ostr << ".";
                ostr.fill(' ');
            }
        }
        else {
            if (this)
                ostr << m_title << "," << m_authorName << "," << m_shelfNumber << "/" << m_bookcaseNumber;
            else ostr << "Invalid Book Record";
        }
        return ostr;
    }
    //overloaded insertion operator to call function to display data
    ostream& operator<<(ostream& ostr, const Book& book)
    {
        book.write(ostr);
        return ostr;
    }
    //overloaded extraction operator to read data from file
    istream& operator>>(istream& istr, Book& book)
    {
        return book.read(istr);
    }
    //read data from file line by line
    istream& Book::read(std::istream& istr)
    {
        char title[MaxTitleLen + 1];
        char authorName[MaxAuthorLen + 1];
        int shelfNumber = 0;
        int bookcaseNumber = 0;
        istr.getline(title, MaxTitleLen + 1, ',');
        istr.getline(authorName, MaxAuthorLen + 1, ',');
        istr >> shelfNumber;
        if (shelfNumber < 1 || shelfNumber > NoOfShelves) {
            istr.setstate(ios::failbit);
        }
        extractChar(istr, '/');
        istr >> bookcaseNumber;
        if (bookcaseNumber < 1 || bookcaseNumber > NoOfBookCases) {
            istr.setstate(ios::failbit);
        }
        if (istr) {
            set(title, authorName, bookcaseNumber, shelfNumber);
        }
        return istr;
    }
}