//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           03.12.2021
//==============================================

/* Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.h
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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Publication.h"
namespace sdds
{
	const int MaxTitleLen = 40;
	const int MaxAuthorLen = 25;
	const int NoOfBookCases = 132;
	const int NoOfShelves = 7;
	class Book : public Publication
	{
	private:
		char* m_authorName{};
	public:
		Book();
		Book(const char* authorName);
		Book(const Book& book);
		~Book();
		Book& operator=(const Book& Ro);
		operator bool() const;
		operator char* () const;
		char type() const;
		void set(int id);
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
	};
}
#endif // !SDDS_BOOK_H