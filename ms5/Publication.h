//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           03.12.2021
//==============================================

/* Citation and Sources...
Final Project Milestone 5
Module: Streamable
Filename: Publication.h
Version 1.0
Author	Volodymyr Labliuk
Revision
-----------------------------------------------------------
Date      Reason
2021/12/03  Preliminary release
2021/12/03  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_PUBLICATION_H__
#define SDDS_PUBLICATION_H__
#include <iostream>
#include "Date.h"
#include "Lib.h"
#include "Streamable.h"
namespace sdds
{
	class Publication : public Streamable
	{
	public:
		Publication();
		// modifier methods
		virtual void set(int member_id);
		// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);
		// Sets the **libRef** attribute value
		void resetDate();
		// Sets the date to the current date of the system.

		//queries methods
		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;
		//Returns the date attribute
		bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;
		//Returns the title attribute
		int getRef()const;
		//Returns the libRef attirbute.

		bool conIO(std::ios& io)const;
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
		operator bool() const;

		//rule of three
		~Publication();
		Publication(const Publication& Ro);
		Publication& operator=(const Publication& Ro);
	private:
		char* m_title{};
		char m_shelfID[SDDS_SHELF_ID_LEN + 1]{};
		int m_membership; 
		int m_libRef;
		Date m_date;
	};
}
#endif