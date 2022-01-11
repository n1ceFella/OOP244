//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           25.11.2021
//==============================================

/***********************************************************************
// OOP244 Workshop 9:
// File	Contact.h
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

#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include "Utils.h"
#include "Person.h"
namespace sdds
{

	const int PROVINCE_LEN = 2; //length of province code
	const int POST_CODE_LEN = 6; //length of postal code

	class Contact : public Person
	{
	public:
		Contact();
		~Contact();
		Contact(const Contact& copyFrom);
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
		Contact& operator=(const Contact& RightOperand);
	private:
		char* m_addres{};
		char* m_city{};
		char m_province[PROVINCE_LEN + 1] = {};
		char m_postCode[POST_CODE_LEN + 1] = {};
	};
}
#endif