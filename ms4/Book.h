//==============================================
// Name:           Volodymyr Labliuk
// Student Number: 147302202
// Email:          vlabliuk@myseneca.ca
// Section:        NBB
// Date:           23.10.2021
//==============================================

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
		void extractChar(std::istream& istr, char ch) const;
		void set(int id);
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr, bool onScreen = true)const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Book& Ro);
	std::istream& operator>>(std::istream& istr, Book& Ro);
}
#endif // !SDDS_BOOK_H