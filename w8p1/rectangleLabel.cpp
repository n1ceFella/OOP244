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
#include "labelShape.h"
#include "rectangleLabel.h"
using namespace std;
namespace sdds
{
	rectangleLabel::rectangleLabel() : labelShape()
	{
		m_width = 0;
		m_spaces = 0;
	}
	rectangleLabel::rectangleLabel(const char* label, int width, int spaces) : labelShape(label)
	{
		m_width = width;
		m_spaces = spaces;
		if (m_width < m_spaces + (int)strlen(label) + 2) {
			m_width = 0;
		}
	}
	void rectangleLabel::readShape(istream& istr)
	{
		labelShape::readShape(istr);
		istr >> m_width;
		istr.ignore();
		istr >> m_spaces;
		istr.ignore(1000, '\n');
	}
	void rectangleLabel::drawShape(ostream& ostr) const
	{
		if (m_width != 0) {
			//first line
			ostr << "+";
			for (int i = 0; i < m_width - 2; i++) {
				ostr << "-";
			}
			ostr << "+" << endl;
			//second line
			ostr << "|";
			ostr.setf(ios::left);
			ostr.width(m_spaces);
			ostr.fill(' ');
			ostr << " ";
			ostr.width(m_width - 2 - m_spaces);
			ostr << label();
			ostr << "|" << endl;
			//last line
			ostr << "+";
			for (int i = 0; i < m_width - 2; i++) {
				ostr << "-";
			}
			ostr << "+";
		}
	}
}