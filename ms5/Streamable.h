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
Filename: Streamable.h
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

#ifndef SDDS_STREAMABLE_H__
#define SDDS_STREAMABLE_H__
#include <iostream>
namespace sdds
{
	class Streamable
	{
	public:
		virtual std::ostream& write(std::ostream& ostr) const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual bool conIO(std::ios& ios) const = 0;
		virtual operator bool() const = 0;
		virtual ~Streamable() = 0;
	};
	std::ostream& operator<<(std::ostream& ostr, Streamable& Ro);
	std::istream& operator>>(std::istream& istr, Streamable& Ro);

	std::istream& operator>>(std::istream& istr, Streamable* Ro);
	std::ostream& operator<<(std::ostream& ostr, Streamable* Ro);
}
#endif
