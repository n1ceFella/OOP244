//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           27.11.2021
//==============================================

/* Citation and Sources...
Final Project Milestone 4
Module: Streamable
Filename: Streamable.cpp
Version 1.0
Author	Volodymyr Labliuk
Revision 
-----------------------------------------------------------
Date      Reason
2021/11/22  Preliminary release
2021/11/22  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include "Streamable.h"
using namespace std;
namespace sdds
{
	Streamable::~Streamable()
	{

	}
	ostream& operator<<(std::ostream& ostr, Streamable& Ro)
	{
		//print only is object is not null
		if (Ro) {
			Ro.write(ostr);
		}
		return ostr;
	}
	istream& operator>>(std::istream& istr, Streamable& Ro)
	{
		Ro.read(istr);
		return istr;
	}
}