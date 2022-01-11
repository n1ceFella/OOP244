//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           20.10.2021
//==============================================


#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;
namespace sdds {

    Contact::Contact()
    {

    }
    Contact::Contact(const char* name, int area, int exCode, int number)
    {
        set(name, area, exCode, number);
    }
    //return true if not nullptr
    Contact::operator bool() const
    {
        return m_name ? true : false;
    }
    //set to safe empty state
    void Contact::setEmpty()
    {
        m_name = nullptr;
    }
    //DMA for name
    void Contact::allocateAndCopy(const char* name)
    {
        delete[] m_name;
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }
    //check phone validity
    bool Contact::validPhone(int areaCode, int exchangeCode, int number) const
    {
        return (
            (areaCode >= 100 && areaCode <= 999) &&
            (exchangeCode >= 100 && exchangeCode <= 999) &&
            (number >= 0 && number <= 9999)
                ) ? true : false;
    }
    //remove redundant character
    void Contact::extractChar(std::istream& istr, char ch) const
    {
        if (istr.peek() == ch) { // checking if the next character in keyboard same as ch
            istr.ignore();
        }
        else {
            istr.setstate(ios::failbit); //set istr to fail state
        }
    }
    //print data formatted
    ostream& Contact::printPhoneNumber(ostream& istr) const
    {
        istr << "(" << m_area << ") " << m_exchangeCode << "-";
        istr.setf(ios::right);
        istr.fill('0');
        istr.width(4);
        istr << m_number;
        istr.unsetf(ios::right);
        return istr;
    }
    //setter for object
    void Contact::set(const char* name, int areaCode, int exchangeCode, int number)
    {
        if(name && name[0] != '\n' && validPhone(areaCode, exchangeCode, number)){
            allocateAndCopy(name);
            m_area = areaCode;
            m_exchangeCode = exchangeCode;
            m_number = number;
        }
        else {
            delete[] m_name;
            setEmpty();
        }
    }
    Contact::~Contact()
    {
        delete[] m_name;
    }
    //copy constrcutor
    Contact::Contact(const Contact& cnt)
    {
        if (cnt) {
            *this = cnt;
        }
    }
    //assigning operator
    Contact& Contact::operator=(const Contact& cnt)
    {
        if (this != &cnt) { //if not self copy
            set(cnt.m_name, cnt.m_area, cnt.m_exchangeCode, cnt.m_number);
        }
        return *this;
    }
    //print data formated
    ostream& Contact::print(ostream& ostr, bool toFile) const
    {
            if (toFile) {
                ostr << m_name << ",";
            }
            else {
                ostr.setf(ios::left);
                ostr.fill('.');
                ostr.width(50);
                ostr << m_name;
                ostr.unsetf(ios::left);
            }
        printPhoneNumber(ostr);
        return ostr;
    }
    //read formatted data
    istream& Contact::read(istream& istr)
    {
        char name[MaxNameLength]{};
        int areaCode;
        int exCode;
        int number;
        istr.get(name, MaxNameLength, ',');
        extractChar(istr ,',');
        extractChar(istr, '(');
        istr >> areaCode;
        extractChar(istr, ')');
        extractChar(istr, ' ');
        istr >> exCode;
        extractChar(istr, '-');
        istr >> number;
        extractChar(istr, '\n');
        if (istr) {
            set(name, areaCode, exCode, number);
        }
        return istr;
    }
    ostream& operator<<(ostream& ostr, const Contact& cnt)
    {
        if (cnt) {
            cnt.print(ostr, false);
        }
        else ostr << "Invalid Phone Record";
        return ostr;
    }
    istream& operator>>(istream& istr, Contact& cnt)
    {
        return cnt.read(istr);
    }
}
