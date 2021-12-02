//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           27.11.2021
//==============================================

/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version 1.0
// Date	2021.11.27
// Author Volodymyr Labliuk
// Description Input validation
//
// Revision History
// -----------------------------------------------------------
// Name                  Date            Reason
// Volodymyr Labliuk   2021.11.27       Validation
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds {
	int getInt(int input, int itemsNum);
	int strLen(const char* str);
	char* dynRead(std::istream& istr, char delimeter = '\n', int size = 0);
	void strCpy(char* des, const char* src);
}
#endif // SDDS_UTILS_H__
