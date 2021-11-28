/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version 1.1
// Date	2021.11.8
// Author Volodymyr Labliuk
// Description ignore funtion impoved
//
// Revision History
// -----------------------------------------------------------
// Name                  Date            Reason
// Volodymyr Labliuk   2021.11.8     ignore funtion impoved
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Utils.h"
#include <string>

namespace sdds {
	//validate input
	int getInt(int input, int itemsNum)
	{
		std::cin >> input;
		while (!std::cin || (input < 0 || input > itemsNum)) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid Selection, try again: ";
			std::cin >> input;
		}
		return input;
	}
	bool conIO(std::ios& io)
	{
		return (&io == &std::cin || &io == &std::cout);
	}
	int strLen(const char* str)
	{
		int len = -1;
		while (str[++len]);
		return len;
	}
	void strCpy(char* des, const char* src)
	{
		while (*src) *des++ = *src++;
		*des = *src;
	}
	char* dynRead(std::istream& istr, char delimeter, int size)
	{
		char* str{};
		std::string toRead;
		//if string to be read is not fixed size
		if (size == 0) {
			getline(istr, toRead, delimeter);
			if (istr) {
				//delete[] str;
				//char* str = nullptr;
				str = new char[strLen(toRead.c_str()) + 1];
				strCpy(str, toRead.c_str());
			}
			//if string to be read is fixed size
		}
		else {
			str = new char[size + 1];
			istr.getline(str, size + 1, delimeter);
		}
		return str;
	}
}