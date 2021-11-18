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
#include "lineLabel.h"
using namespace std;
namespace sdds
{
	lineLabel::lineLabel() : labelShape()
	{
		m_length = 0;
	}
	lineLabel::lineLabel(const char* label, int length) : labelShape(label)
	{
		m_length = length;
	}
	void lineLabel::readShape(istream& istr)
	{
		labelShape::readShape(istr);
		int length;
		istr >> length;
		m_length = length; // ?????????????
		istr.ignore(1000, '\n');
	}
	void lineLabel::drawShape(ostream& ostr)
	{
		if (m_length > 0 && label()) {
			ostr << label() << endl;
			//width and fill
			for (int i = 0; i < m_length; i++) {
				cout << "=";
			}
		}
	}
}