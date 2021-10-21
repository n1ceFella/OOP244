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
        setEmpty();
    }

    Contact::Contact(const char* name, int area, int exCode, int number)
    {
            set(name, area, exCode, number);
    }

    Contact::operator bool() const
    {
        return m_name ? true : false;
    }

    void Contact::setEmpty()
    {
        m_name = nullptr;
    }

    void Contact::allocateAndCopy(const char* name)
    {
        delete[] m_name;
        m_name = new char[strlen(name + 1)];
        strcpy(m_name, name);
    }

    bool Contact::validPhone(int areaCode, int exchangeCode, int number) const
    {
        return (
            (areaCode >= 100 && areaCode <= 999) &&
            (exchangeCode >= 100 && exchangeCode <= 999) &&
            //(isInt(number) && 
            (number >= 0 && number <= 9999)
                ) ? true : false;
    }

    bool Contact::validName(const char* name) const 
    {
        return (name && name[0] != '\n') ? true : false;
    }
    bool Contact::isValidContact() const
    {
        return (validName(m_name) && validPhone(m_area, m_exchangeCode, m_number));
    }
    void Contact::extractChar(std::istream& istr, char ch) const
    {

        char next = istr.peek();
        if (next == ch) { // checking if the next character in keyboard same as ch
            istr.ignore();
            //cout << "You did not enter a number!";
        }
        else {
            istr.setstate(ios::failbit);
        }
        //cin.ignore(1000, '\n'); // flush the invalid value or everything after the number.
    }

    ostream& Contact::printPhoneNumber(ostream& istr) const
    {
        istr << "(" << m_area << ") " << m_exchangeCode << "-";
        istr.setf(ios::right);
        istr.fill('0');
        istr.width(4);
        istr << m_number;
        return istr;
    }

    void Contact::set(const char* name, int areaCode, int exchangeCode, int number)
    {
        //if (*this) {
        if(validName(name) && validPhone(areaCode, exchangeCode, number)){
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

    Contact::Contact(const Contact& cnt)
    {
        //if (*this) {
        if(cnt.isValidContact()){
            *this = cnt;
        }
    }

    Contact& Contact::operator=(const Contact& cnt)
    {
        if (this != &cnt) {
            set(cnt.m_name, cnt.m_area, cnt.m_exchangeCode, cnt.m_number);
        }
        return *this;
    }

    ostream& Contact::print(ostream& ostr, bool toFile) const
    {
        //if (validName(m_name) && validPhone(m_area, m_exchangeCode, m_number)) {
            if (toFile) {
                ostr << m_name << ",";
                printPhoneNumber(ostr);
            }
            else {
                ostr.unsetf(ios::right);
                ostr.setf(ios::left);
                ostr.fill('.');
                ostr.width(50);
                ostr << m_name;
                printPhoneNumber(ostr);
            }
        //}
        return ostr;
    }
    istream& Contact::read(istream& istr)
    {
        char name[MaxNameLength];
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
        //if (cnt.validName(m_name) && cnt.validPhone(m_area, m_exchangeCode, m_number)) {
        //if (cnt) {
        if(cnt.isValidContact()){
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
