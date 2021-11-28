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
#include "Utils.h"
using namespace std;
namespace sdds
{
    Book::Book() : Publication(){}
    Book::Book(const char* authorName)
    {
      
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
        delete[] m_authorName;
    }
    Book& Book::operator=(const Book& Ro)
    {
        if ((this != &Ro) && Ro) { //if not self copy
            Publication::operator=(Ro);
            delete[] m_authorName;
            m_authorName = new char[strlen(Ro.m_authorName) + 1];
            strcpy(m_authorName, Ro.m_authorName);
           // delete[] Ro.m_authorName;
        }
        return *this;
    }
    //return true if not nullptr
    Book::operator bool() const
    {
        return m_authorName && Publication::operator bool();
    }
    Book::operator char* () const
    {
        return m_authorName;
    }
    char Book::type() const
    {
        return 'B';
    }
    void Book::set(int id)
    {
        Publication::set(id);
        resetDate();
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
        Publication::write(ostr);
        if (conIO(ostr)) {
            ostr << " ";
            for (unsigned int i = 0; i < strlen(m_authorName) && i < SDDS_AUTHOR_WIDTH; i++) {
                if (i == strlen(m_authorName) - 1) {
                    ostr.setf(ios::left);
                    ostr.width(SDDS_AUTHOR_WIDTH - strlen(m_authorName) + 1);
                    ostr << m_authorName[i];
                    ostr.unsetf(ios::left);
                }
                else {
                    ostr << m_authorName[i];
                }
            }
            ostr << " |";
        }
        else {
            ostr << '\t' << m_authorName;
        }
        return ostr;
    }
    //read data from file line by line
    istream& Book::read(std::istream& istr)
    {
        char authorName[256 + 1];
        Publication::read(istr);
        if (conIO(istr)) {
            istr.ignore();
            cout << "Author: ";
            istr.getline(authorName, 256 + 1, '\n');
        }
        else {
            istr.ignore();
            //istr.getline(authorName, 256 + 1, '\n');
            istr.get(authorName, 256 + 1, '\n');
        }
        if (istr) {
            delete[] m_authorName;
            m_authorName = new char[strlen(authorName) + 1];
            strcpy(m_authorName, authorName);
        }
        return istr;
    }
    //overloaded insertion operator to call function to display data
    ostream& operator<<(ostream& ostr, const Book& Ro)
    {
        if (Ro) {
            Ro.write(ostr);
        }
        return ostr;
    }
    //overloaded extraction operator to read data from file
    istream& operator>>(istream& istr, Book& book)
    {
        book.read(istr);
        return istr; 
    }
}