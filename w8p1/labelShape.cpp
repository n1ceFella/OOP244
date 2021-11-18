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
using namespace std;
namespace sdds
{
	labelShape::labelShape()
	{

	}
	labelShape::labelShape(const char* label)
	{
		delete[] m_label;
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}
	labelShape::~labelShape()
	{
		delete[] m_label;
	}
	char* labelShape::label()const 
	{
		return m_label;
	}
	void labelShape::readShape(istream& istr)
	{
		char label[100];
		//char * label{}
		istr >> label;

		istr.getline(label, 100, ',');
		// ignore
		delete[] m_label;
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}
}