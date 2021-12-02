//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           27.11.2021
//==============================================

/* Citation and Sources...
Final Project Milestone 4
Module: Date
Filename: Date.cpp
Version 1.2
Author	Volodymyr Labliuk
Revision History clearing keyboard removed from read function
and added external variables
-----------------------------------------------------------
Date      Reason
2021/11/2  Preliminary release
2021/11/2  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

// Final Project Milestone 1 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2021/10/29		Preliminary release
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include "Date.h"
using namespace std;
namespace sdds {

   bool sdds_test = false;
   int sdds_year = 2021;
   int sdds_mon = 12;
   int sdds_day = 25;

   bool Date::validate() {
      errCode(NO_ERROR);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
         errCode(YEAR_ERROR);
      }
      else if (m_mon < 1 || m_mon > 12) {
         errCode(MON_ERROR);
      }
      else if (m_day < 1 || m_day > mdays()) {
         errCode(DAY_ERROR);
      }
      return !bad();
   }
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }
   int Date::systemYear()const
   {
       int theYear = sdds_year;
       if (!sdds_test) {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           theYear = lt.tm_year + 1900;
       }
       return theYear;
   }
   void Date::setToToday()
   {
       if (sdds_test) {
           m_day = sdds_day;
           m_mon = sdds_mon;
           m_year = sdds_year;
       }
       else {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           m_day = lt.tm_mday;
           m_mon = lt.tm_mon + 1;
           m_year = lt.tm_year + 1900;
       }
       errCode(NO_ERROR);
   }
   int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01 
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }
   Date::Date() :m_CUR_YEAR(systemYear()) {
      setToToday();
   }
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }
   const char* Date::dateStatus()const {
      return DATE_ERROR[errCode()];
   }
   int Date::currentYear()const {
      return m_CUR_YEAR;
   }
   void Date::errCode(int readErrorCode) {
      m_ErrorCode = readErrorCode;
   }
   int Date::errCode()const {
      return m_ErrorCode;
   }
   bool Date::bad()const {
      return m_ErrorCode != 0;
   }
  
   ostream& operator<<(ostream& os, const Date& RO) {
      return RO.write(os);
   }
   istream& operator>>(istream& is, Date& RO) {
      return RO.read(is);
   }
   //read date from keyboard
   std::istream& Date::read(std::istream& is)
   {
       errCode(0);

       is >> m_year;
       is.ignore();
       is >> m_mon;
       is.ignore();
       is >> m_day;

       if (is) {
           validate();
       }
       else {
           errCode(1);
       }
       return is;
   }

   //if valid, print data, otherwise print error message
   std::ostream& Date::write(std::ostream& os)const
   {
       if (bad()) {
           cout << dateStatus();
       }
       else {
           os << m_year << "/";
           os.fill('0');
           os.width(2);
           os.setf(ios::right);
           os << m_mon;
           os << "/";
           os.fill('0');
           os.setf(ios::right); 
           os << m_day;
           os.fill(' ');
           os.unsetf(ios::right);
       }
       return os;
   }
   //check if dates are equal
   bool Date::operator==(const Date& right) const
   {
       return daysSince0001_1_1() == right.daysSince0001_1_1();
   }
   //check if dates are not equal
   bool Date::operator!=(const Date& right) const
   {
       return daysSince0001_1_1() != right.daysSince0001_1_1();
   }
   //check if left greater or equal to right
   bool Date::operator>=(const Date& right) const 
   {
       return daysSince0001_1_1() >= right.daysSince0001_1_1();
   }
   //check if left smaller or equal to right
   bool Date::operator<=(const Date& right) const 
   {
       return daysSince0001_1_1() <= right.daysSince0001_1_1();
   }
   //check if left smaller hen right
   bool Date::operator<(const Date& right) const 
   {
       return daysSince0001_1_1() < right.daysSince0001_1_1();
   }
   //check if left greater hen right
   bool Date::operator>(const Date& right) const 
   {
       return daysSince0001_1_1() > right.daysSince0001_1_1();
   }
   //get different between dates in days
   int Date::operator-(const Date& right) const
   {
       return daysSince0001_1_1() - right.daysSince0001_1_1();
   }
   //check if data are valid
   Date::operator bool() const
   {
       return !bad();
   }

}
