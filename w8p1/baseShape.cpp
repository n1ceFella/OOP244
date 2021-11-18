//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           15.11.2021
//==============================================

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "baseShape.h"
using namespace std;
namespace sdds
{
	baseShape::~baseShape()
	{

	}
	ostream& operator<<(ostream& ostr, baseShape& baseShape)
	{
		baseShape.drawShape(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, baseShape& baseShape)
	{
		baseShape.readShape(istr);
		return istr;
	}
}