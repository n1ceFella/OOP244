//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           25.11.2021
//==============================================

/***********************************************************************
// OOP244 Workshop 9:
// File	Utils.cpp
// Version 1.1
// Date	2021/11/25
// Author	Volodymyr Labliuk
// Description  
//  dynRead function modified so that we can read fixed size variable
// Revision History
// -----------------------------------------------------------
// Name Volodymyr Labliuk    Date 25.11.2021    Reason dynRead modified
///////////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "Utils.h"
namespace sdds {
   int strLen(const char* str)  {
      int len = -1;
      while (str[++len]);
      return len;
   }
   void strCpy(char* des, const char* src) {
      while (*src) *des++ = *src++;
      *des = *src;
   }
   void strCat(char* des, const char* src) {
      while (*des) des++;
      while (*src) *des++ = *src++;
      *des = *src;
   }
   void delAlloCopy(char*& des, const char* src) {
      delete[] des;
      des = nullptr;
      if (src && src[0]) {
         des = new char[strLen(src) + 1];
         strCpy(des, src);
      }
   }
   char* dynRead(istream& istr, char delimeter, int size) {
      char* str{};
      string toRead;
      //if string to be read is not fixed size
      if (size == 0) {
          getline(istr, toRead, delimeter);
          if (istr) {
              str = new char[strLen(toRead.c_str()) + 1];
              strCpy(str, toRead.c_str());
          }
      //if string to be read is fixed size
      } else {
          str = new char[size + 1];
          istr.getline(str, size + 1, delimeter);
      } 
      return str;
   }
}