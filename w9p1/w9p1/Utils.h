//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           25.11.2021
//==============================================

/***********************************************************************
// OOP244 Workshop 9: 
// File	Utils.h
// Version 1.0
// Date	2021/11/19
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
#include <fstream>
namespace sdds {
   int strLen(const char* str);
   void strCpy(char* des, const char* src);
   void strCat(char* des, const char* src);
   void delAlloCopy(char*& des, const char* src);
   char* dynRead(std::istream& istr, char delimeter = '\n', int size = 0 );
}
#endif // !
