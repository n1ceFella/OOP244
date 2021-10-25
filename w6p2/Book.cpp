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
    Book::Book(const Book& cnt)
    {
        if (cnt) {
            *this = cnt;
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
        return m_authorName && m_title ? true : false;
    }
    Book& Book::operator=(const Book& cnt)
    {
        if (this != &cnt) { //if not self copy
            set(cnt.m_title, cnt.m_authorName, cnt.m_bookcaseNumber, cnt.m_shelfNumber);
        }
        return *this;
    }
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
    //DMA for name
    void Book::allocateAndCopyAuthorName(const char* name)
    {
        delete[] m_authorName;
        m_authorName = new char[strlen(name) + 1];
        strcpy(m_authorName, name);
    }
    void Book::allocateAndCopyTitle(const char* name)
    {
        delete[] m_title;
        m_title = new char[strlen(name) + 1];
        strcpy(m_title, name);
    }
    bool Book::isValid(char* title, char* authorName, int bookcaseNum, int shelfNum)const
    {
        return (title && title[0] != '\n') &&
            (authorName && authorName[0] != '\n') &&
            (bookcaseNum > 0 && bookcaseNum <= NoOfBookCases) &&
            (shelfNum > 0 && shelfNum <= NoOfShelves);
    }
    void Book::extractChar(std::istream& istr, char ch) const
    {
        if (istr.peek() == ch) { // checking if the next character in keyboard same as ch
            istr.ignore();
        }
        else {
            istr.setstate(ios::failbit); //set istr to fail state
        }
    }
    istream& Book::read(std::istream& istr)
    {
        char title[MaxTitleLen + 1]{};
        char authorName[MaxAuthorLen + 1]{};
        int shelfNumber;
        int bookcaseNumber;

        //cout << istr.tellg() << endl;
        //istr.get(title, MaxTitleLen, ',');
       // while (istr.getline(title, MaxTitleLen, ',')) {
         //   istr.getline(authorName, MaxAuthorLen, ',');
        //}
        //istr.ignore();
        //cout << istr.tellg() << endl;
        istr.getline(title, MaxTitleLen + 1, ',');
        //istr.clear();
        //cout << istr.tellg() << endl;
        //extractChar(istr, ',');
        //istr.seekg(strlen(title) + 1);
        //istr.get(authorName, MaxAuthorLen, ',');
        istr.getline(authorName, MaxAuthorLen + 1, ',');
        //str.clear();
        //cout << istr.tellg() << endl;

        //extractChar(istr, ',');
        istr >> shelfNumber;
        extractChar(istr, '/');
        istr >> bookcaseNumber;
        extractChar(istr, '\n');
        //if(!isValid(title, authorName, bookcaseNumber, shelfNumber))
        ////if(!(bookcaseNumber > 0 && bookcaseNumber <= NoOfBookCases &&
        //    //shelfNumber > 0 && shelfNumber <= NoOfShelves))
        //{ 
        //    istr.clear();
        //    istr.ignore(MaxAuthorLen + MaxTitleLen + 7, '\n');
        //    istr.setstate(ios::failbit);
        //    return istr;
        //}
        if (!isValid(title, authorName, bookcaseNumber, shelfNumber)) {
            istr.setstate(ios::failbit);
            set(title, authorName, bookcaseNumber, shelfNumber);
        }
        else {
            if (istr) {
                set(title, authorName, bookcaseNumber, shelfNumber);
            }
            else {
                //    istr.setstate(ios::goodbit);
                istr.clear();
                istr.ignore(MaxAuthorLen + MaxTitleLen + 7, '\n');
                istr.setstate(ios::failbit);
            }
        }
        //int x = istr.tellg();
        //istr.seekg(x - strlen(title) - strlen(authorName) - 7);
        return istr;
    }
    ostream& Book::write(ostream& ostr, bool onScreen)const
    {
        if (onScreen) {
            if (*this) {
                ostr.setf(ios::left);
                ostr.width(39);
                ostr << m_title;
                ostr << " | ";
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
    ostream& operator<<(ostream& ostr, const Book& cnt)
    {
        //if (cnt) {
            cnt.write(ostr);
        //}
        return ostr;
    }
    istream& operator>>(istream& istr, Book& cnt)
    {
        return cnt.read(istr);
    }
}