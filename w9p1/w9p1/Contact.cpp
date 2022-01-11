//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           25.11.2021
//==============================================

/***********************************************************************
// OOP244 Workshop 9:
// File	Contact.cpp
// Version 1.0
// Date	2021/11/25
// Author	Volodymyr Labliuk
// Student ID: 147302202
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "Utils.h"
#include "Person.h"
#include "Contact.h"
using namespace std;
namespace sdds
{
	Contact::Contact() : Person()
	{

	}
	Contact::~Contact()
	{
		delete[] m_addres;
		delete[] m_city;
		m_addres = m_city = nullptr;
		m_province[0] = '\0';
		m_postCode[0] = '\0';
	}
	//copy constructor
	Contact::Contact(const Contact& copyFrom)
	{
		operator=(copyFrom);
	}
	//assignment operator
	Contact& Contact::operator=(const Contact& RightOperand)
	{
		if (this != &RightOperand) {
			Person::operator=(RightOperand);
			delAlloCopy(m_addres, RightOperand.m_addres);
			delAlloCopy(m_city, RightOperand.m_city);
			strCpy(m_province, RightOperand.m_province);
			strCpy(m_postCode, RightOperand.m_postCode);
		}
		return *this;
	}
	//read data
    istream& Contact::read(std::istream& istr)
    {
		//temporary pointers to store data
		char* address{};
		char* city{};
		char* prov{};
		char* post{};

		//read and store data
		Person::read(istr);
		address = dynRead(istr, ',');
		city = dynRead(istr, ',');
		delAlloCopy(m_addres, address);
		delAlloCopy(m_city, city);
		prov = dynRead(istr, ',', PROVINCE_LEN);
		post = dynRead(istr, '\n', POST_CODE_LEN);
		if(prov) strCpy(m_province, prov);
		if(post) strCpy(m_postCode, post);
		//free memory
		delete[] prov;
		delete[] post;
		delete[] address;
		delete[] city;

		if (istr.fail() ||  !m_addres || !m_city || (strLen(m_postCode) != 6) || (strLen(m_province) != 2)) { //!m_address
			Person::operator~();
			delete[] m_addres;
			delete[] m_city;
			m_addres = m_city = nullptr;
			m_postCode[0] = '\0';
			m_province[0] = '\0';
		} 
		return istr;
    }
	//print data
    ostream& Contact::write(std::ostream& ostr) const
    {
		Person::write(ostr);
		if (*this) {
			ostr << endl << m_addres << endl;
			ostr << m_city << " " << m_province << endl;
			for (int i = 0; i < POST_CODE_LEN; i++) {
				ostr << m_postCode[i];
				if (i == 2) ostr << " ";
			}
			ostr << endl;
		}
		return ostr;
    }
}