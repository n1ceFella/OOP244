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
}